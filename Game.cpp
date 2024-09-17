#include "Game.h"
#include "HairMetalZombie.h"
#include "RegularZombie.h"

const int WINDOW_X = 800;
const int WINDOW_Y = 600;

const float BEGIN_OF_BOARD_X = 150.f;
const float BEGIN_OF_BOARD_Y = 90.f;
const float END_OF_BOARD_X = 660.f;
const float END_OF_BOARD_Y = 550.f;

const int START_SUN_NUM = 50;
const int ADD_POINT_PER_SUN = 25;

const float ZOMBIE_GENERATE_INTERVAL = 5.0f;
const int ZOMBIE_NUM_FREQUENCY_PER_WAVE = 3;
const int BIG_ZOMBIE_PER_ZOMBIE = 3;

const int FIRST_ROUND_DELAY = 30;
const int OTHER_ROUND_DELAY = 10;
const int NUMBER_OF_WAVE = 4;

const int SUNFLOWER_PRICE = 50;
const int WALNUT_PRICE = 50;
const int REGULAR_PEA_SHOOTER_PRICE = 100;
const int ICY_PEA_SHOOTER_PRICE = 150;
const int WATERMELON_PRICE = 200;

const std::string BACK_GROUND_PATH = "extrafile/ext8waid79e81.jpg";
const std::string GAME_OVER_PIC_PATH = "extrafile/endpage.png";
const std::string SUN_PIC_PATH = "extrafile/sun.png";

const std::string BACK_GROUND_MUSIC_PATH = "extrafile/Main-Music.ogg";
const std::string GAME_OVER_MUSIC_PATH = "extrafile/GameOverMusic.ogg";
const std::string WIN_MUSIC_PATH = "extrafile/WinMusic.ogg";

const std::string ROUND_FONT_PATH = "extrafile/BROMPH_TOWN.ttf";
const std::string STAR_NUM_FONT_PATH = "extrafile/Dosis-Light.ttf";



void Game::initWindow()
{
	this->videoMode = sf::VideoMode(WINDOW_X , WINDOW_Y);
	this->window = new sf::RenderWindow(videoMode , "Plant vs Zombie");
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

Game::Game(){
	sunsNum = START_SUN_NUM;

	sf::Vector2f beginOfBoard;
	beginOfBoard.x = BEGIN_OF_BOARD_X;
	beginOfBoard.y = BEGIN_OF_BOARD_Y;
	sf::Vector2f endOfBoard;
	endOfBoard.x = END_OF_BOARD_X;
	endOfBoard.y = END_OF_BOARD_Y;

	this->board = new Board(beginOfBoard , endOfBoard);

	this->gameOverSound = true;
	this->winSound = true;
	this->isDone = false;
	this->isGameOver = false;
	this->attacking = false;
	this->isPressedBeforForSun = false;
	this->isPressedBeforForWalnut =false;
	this->isPressedBeforForRegularPeaShooter = false;
	this->isPressedBeforForIcyPeaShooter = false;
	this->isPressedBeforForWatermelon = false;
	this->waveNum = 1;
	this->zombieAddedInWave=0;
	this->initWindow();

	this->music.openFromFile(BACK_GROUND_MUSIC_PATH);
	this->music.setLoop(true);
	this->music.play();
	this->gameOverMusic.openFromFile(GAME_OVER_MUSIC_PATH);
	this->winMusic.openFromFile(WIN_MUSIC_PATH);

	this->sunFlowerPriceRectangle = new SunFlowerPriceRectangle();
	this->walnutPriceRectangle = new WalnutPriceRectangle();
	this->regularPeaShooterPriceRectangle = new RegularPeaShooterPriceRectangle();
	this->icyPeaShooterPriceRectangle = new IcyPeaShooterPriceRectangle();
	this->watermelonShooterPriceRectangle = new WatermelonShooterPriceRectangle();

	this->sunflower = new SunFlower();
	this->walnut = new Walnut();
	this ->regularPeaShooter = new RegularPeaShooter();
	this->icyPeaShooter = new IcyPeaShooter();
	this->watermelonShooter = new WatermelonShooter();
}

Game::~Game()
{
	delete this->window;
	for(auto zombie : this->zombies)
		delete zombie;
	for(auto sun : this->suns)
		delete sun;
	delete this->board;
}

void Game::addNewNormalZombie(){
	this->zombies.push_back(new RegularZombie());
}

void Game::addNewBigZombie(){
	this->zombies.push_back(new HairMetalZombie());
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::beginAttackIfItsTime(){
	int numberOfZombies = waveNum * ZOMBIE_NUM_FREQUENCY_PER_WAVE;
	float zombieGenerateTime = numberOfZombies*ZOMBIE_GENERATE_INTERVAL;
	int waitingTimeBeforNewRound;
	if(this->waveNum == 1){
		waitingTimeBeforNewRound = FIRST_ROUND_DELAY;
	}
	else{
		waitingTimeBeforNewRound = OTHER_ROUND_DELAY;
	}
	if(!attacking && waveAttackClock.getElapsedTime().asSeconds() >= waitingTimeBeforNewRound){
		attacking = true;
		waveAttackClock.restart();
	}

	if(attacking && waveAttackClock.getElapsedTime().asSeconds()<=zombieGenerateTime){
		if (zombiAttackClock.getElapsedTime().asSeconds() >= ZOMBIE_GENERATE_INTERVAL) {
			zombieAddedInWave += 1;
			if (zombieAddedInWave % BIG_ZOMBIE_PER_ZOMBIE == 0){
				addNewBigZombie();
			} else {
				addNewNormalZombie();
			}
			zombiAttackClock.restart();
		}
	}

	if(attacking && waveAttackClock.getElapsedTime().asSeconds()>=zombieGenerateTime && zombies.size()== 0){
		attacking = false;
		waveNum += 1;
		if(waveNum == NUMBER_OF_WAVE + 1){
			isDone = true;
			if(winSound){
				this->music.stop();
				this->winMusic.play();
				winSound = false;
			}
		}
		showingRound.restart();
		zombieAddedInWave = 0;
		waveAttackClock.restart();

	}
		
}

void Game::ShowGameOverPic(){
	sf::Texture texture;
    texture.loadFromFile(GAME_OVER_PIC_PATH);
    sf::Sprite sprite(texture);
	sprite.setTexture(texture);
	sprite.setPosition(150,90);
    sprite.setScale(1, 1);
    this->window->draw(sprite);
}

void Game::gameOver(){
	for(int i=0 ; i<zombies.size() ; i++){
		if(zombies[i]->hasArrivedHome()){
			this->isGameOver = true;
			if(gameOverSound){
				this->music.stop();
				this->gameOverMusic.play();
				gameOverSound = false;
			}
			break;
		}
	}
}


void Game::ShowBackGround(std::string backgroundPath){
    sf::Texture texture;
    texture.loadFromFile(backgroundPath);
    sf::Sprite sprite(texture);
	sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(this->videoMode.width) / texture.getSize().x;
    float scaleY = static_cast<float>(this->videoMode.height) / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);
    this->window->draw(sprite);
	this->window->getSize();
}

void Game::showRound(){
	if(showingRound.getElapsedTime().asSeconds() <= 2){
		sf::Font font;
		font.loadFromFile(ROUND_FONT_PATH);
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(325 , 225);
		if(!isDone){
			text.setString("Round " + std::to_string(waveNum));
			this->window->draw(text);
		}
	}
}

void Game::showWonState(){
		sf::Font font;
		font.loadFromFile(ROUND_FONT_PATH);
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(300 , 225);
		text.setString("YOU WON!!!");
		this->window->draw(text);
}

void Game::showSunRectangle(){
	sf::RectangleShape rectangle(sf::Vector2f(75.f, 30.f));
    rectangle.setFillColor(sf::Color::Black);
	rectangle.setOrigin(rectangle.getLocalBounds().width / 2, rectangle.getLocalBounds().height / 2);
    rectangle.setPosition(92 , 25);

	sf::Text text;
    text.setString(std::to_string(this->sunsNum));
	text.setOrigin(15, 12);
    text.setCharacterSize(20);
	text.setColor(sf::Color::White);

    sf::Font font;
    font.loadFromFile(STAR_NUM_FONT_PATH);
    text.setFont(font);
	text.setPosition(92 , 25);
	this->window->draw(rectangle);
    this->window->draw(text);
}

void Game::showSunsNum(){
	sf::Texture sun;
	sun.loadFromFile(SUN_PIC_PATH);
	sf::Sprite sunSprite;
	sunSprite.setTexture(sun);
	sunSprite.setScale(.15f,.15f);
	sunSprite.setOrigin(sun.getSize().x/2 , sun.getSize().y/2);
	sunSprite.setPosition(25,25);
	this->window->draw(sunSprite);
	this->showSunRectangle();
}

void Game::fallingSuns(){
	if(sunClock.getElapsedTime().asSeconds() >= 10){
		Sun* newFallingSun = new Sun(1);
		sf::Vector2f fallingSunPos = {BEGIN_OF_BOARD_X + static_cast<float>(rand() % static_cast<int>(550)) ,0.f};
		newFallingSun->setPosition(fallingSunPos.x , fallingSunPos.y);
		suns.push_back(newFallingSun);
		sunClock.restart();
	}
}

void Game::updateMousePositions(){
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateSuns(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if (this->mouseHeld == false){
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->suns.size() && deleted == false; i++){
				if (this->suns[i]->getSprite().getGlobalBounds().contains(this->mousePosView)){
					this->sunsNum += ADD_POINT_PER_SUN;
					deleted = true;
					this->suns.erase(this->suns.begin() + i);
				}
			}
		}
	}
	else{
		this->mouseHeld = false;
	}
}


void Game::clearDownSun(){
	for(int i=0 ; i<suns.size() ; i++)
		if(suns[i]->hasArrivedToDown()){
			delete suns[i];
			suns.erase(suns.begin() + i);
		}
}

bool Game::plantIsOnBoard(sf::Vector2f mousePositionFloat){
	return this->board->isContain(mousePositionFloat);
}

bool Game::notClickForOther(){
	return !(this->isPressedBeforForIcyPeaShooter || this->isPressedBeforForRegularPeaShooter ||
			 this->isPressedBeforForSun || this->isPressedBeforForWalnut);
}

void Game::addNewSunFlower(){
	if(this->isPressedBeforForSun && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) 
		&& this->board->isCellEmpty(this->mousePosView)){
		SunFlower* newSunFlower = new SunFlower();
		sf::Vector2f posOfAddedSunflower = this->board->plantAt(this->mousePosView , newSunFlower);
		newSunFlower->setPosition(posOfAddedSunflower);
		plants.push_back(newSunFlower);
		this->sunFlowerPriceRectangle->startCoolDown();
		this->sunsNum -= SUNFLOWER_PRICE;
		this->isPressedBeforForSun = false;
	}
	if(this->isPressedBeforForSun || this->sunFlowerPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForSun || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->sunFlowerPriceRectangle->isAbleToAdd() 
			&& this->sunsNum >= SUNFLOWER_PRICE && this->notClickForOther()){
			this->sunflower->setPosition(this->mousePosView);
			this->sunflower->render(*this->window);
			this->isPressedBeforForSun = true;
		}
	}
}

void Game::addNewWalnut(){
	if(this->isPressedBeforForWalnut && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) 
		&& this->board->isCellEmpty(this->mousePosView)){
		Walnut* newWalnut = new Walnut();
		sf::Vector2f posOfAddedWalnut = this->board->plantAt(this->mousePosView , newWalnut);
		newWalnut->setPosition(posOfAddedWalnut);
		plants.push_back(newWalnut);
		this->walnutPriceRectangle->startCoolDown();
		this->sunsNum -= WALNUT_PRICE;
		this->isPressedBeforForWalnut = false;
	}
	if(this->isPressedBeforForWalnut || this->walnutPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForWalnut || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->walnutPriceRectangle->isAbleToAdd()  
			&& this->sunsNum >= WALNUT_PRICE && this->notClickForOther()){
			this->walnut->setPosition(this->mousePosView);
			this->walnut->render(*this->window);
			this->isPressedBeforForWalnut = true;
		}
	}
}

void Game::addNewRegularPeaShooter(){
	if(this->isPressedBeforForRegularPeaShooter && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) 
		&& this->board->isCellEmpty(this->mousePosView)){
		RegularPeaShooter* regularPeaShooter = new RegularPeaShooter();
		sf::Vector2f posOfAddedRegularPeaShooter = this->board->plantAt(this->mousePosView , regularPeaShooter);
		regularPeaShooter->setPosition(posOfAddedRegularPeaShooter);
		plants.push_back(regularPeaShooter);
		this->regularPeaShooterPriceRectangle->startCoolDown();
		this->sunsNum -= REGULAR_PEA_SHOOTER_PRICE;
		this->isPressedBeforForRegularPeaShooter = false;
	}
	if(this->isPressedBeforForRegularPeaShooter || this->regularPeaShooterPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForRegularPeaShooter || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->regularPeaShooterPriceRectangle->isAbleToAdd() 
			&& this->sunsNum >= REGULAR_PEA_SHOOTER_PRICE && this->notClickForOther()){
			this->regularPeaShooter->setPosition(this->mousePosView);
			this->regularPeaShooter->render(*this->window);
			this->isPressedBeforForRegularPeaShooter = true;
		}
	}
}

void Game::addNewIcyPeaShooter(){
	if(this->isPressedBeforForIcyPeaShooter && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) 
		&& this->board->isCellEmpty(this->mousePosView)){
		IcyPeaShooter* icyPeaShooter = new IcyPeaShooter();
		sf::Vector2f posOfAddedIcyPeaShooter = this->board->plantAt(this->mousePosView , icyPeaShooter);
		icyPeaShooter->setPosition(posOfAddedIcyPeaShooter);
		plants.push_back(icyPeaShooter);
		this->icyPeaShooterPriceRectangle->startCoolDown();
		this->sunsNum -= ICY_PEA_SHOOTER_PRICE;
		this->isPressedBeforForIcyPeaShooter = false;
	}
	if(this->isPressedBeforForIcyPeaShooter || this->icyPeaShooterPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForIcyPeaShooter || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->icyPeaShooterPriceRectangle->isAbleToAdd() 
			&& this->sunsNum >= ICY_PEA_SHOOTER_PRICE && this->notClickForOther()){
			this->icyPeaShooter->setPosition(this->mousePosView);
			this->icyPeaShooter->render(*this->window);
			this->isPressedBeforForIcyPeaShooter = true;
		}
	}
}

void Game::addNewWatermelonShooter(){
	if(this->isPressedBeforForWatermelon && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) 
		&& this->board->isCellEmpty(this->mousePosView)){
		WatermelonShooter* watermelonShooter = new WatermelonShooter();
		sf::Vector2f posOfAddedWatermelonShooter = this->board->plantAt(this->mousePosView , watermelonShooter);
		watermelonShooter->setPosition(posOfAddedWatermelonShooter);
		plants.push_back(watermelonShooter);
		this->watermelonShooterPriceRectangle->startCoolDown();
		this->sunsNum -= WATERMELON_PRICE;
		this->isPressedBeforForWatermelon = false;
	}
	if(this->isPressedBeforForWatermelon || this->watermelonShooterPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForWatermelon || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->watermelonShooterPriceRectangle->isAbleToAdd() 
			&& this->sunsNum >= WATERMELON_PRICE && this->notClickForOther()){
			this->watermelonShooter->setPosition(this->mousePosView);
			this->watermelonShooter->render(*this->window);
			this->isPressedBeforForWatermelon = true;
		}
	}
}

void Game::checkZombiePlantCollision(){
    for(auto &zombie : zombies){
        for(auto &plant : plants){
            sf::FloatRect plantBounds = plant->getSprite().getGlobalBounds();
            sf::FloatRect zombieBounds = zombie->getSprite().getGlobalBounds();
			sf::Vector2f zombieCenter = sf::Vector2f(
                zombieBounds.left + zombieBounds.width / 2.0f,
                zombieBounds.top + zombieBounds.height / 2.0f);
            if(plantBounds.contains(zombieCenter)){
                zombie->startEating(plant);
                break;
            }
			else{
				zombie->isNotEating();
			}
        }
    }
}

void Game::checkZombiePeaCollision(){
	for(auto pea : projectiles){
		for(auto zombie : zombies){
			sf::FloatRect zombieBounds = zombie->getSprite().getGlobalBounds();
			sf::FloatRect peaBound = pea->getSprite().getGlobalBounds();
			sf::Vector2f peaCenter = sf::Vector2f(
                peaBound.left + peaBound.width / 2.0f,
                peaBound.top + peaBound.height / 2.0f);
			if(zombieBounds.contains(peaCenter)){
				zombie->hitByPea(pea);
				pea->getHit();
				break;
			}
		}
	}
}

bool Game::isZombiAreInLineOf(Plant* plant){
	for(auto zombi :zombies){
		if(zombi->isInSameLine(plant->getSprite().getPosition())){
			return true;
		}
	}
	return false;
}

sf::Vector2f Game::fineNearestZombie(Plant* plant , Watermelon* newWatermelon){
	for(int i =0 ; i<zombies.size() ; i++){
		if(zombies[i]->isInSameLine(plant->getSprite().getPosition())){
			newWatermelon->assignZombi(zombies[i]);
			return zombies[i]->getSprite().getPosition();
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->beginAttackIfItsTime();
	this->fallingSuns();
	this->gameOver();
	for(auto zombie : this->zombies){
		if(!zombie->isEating())
			zombie->move(-1.f,0.f);
	}
	for(auto sun : this->suns)
		sun->move(0.f,1.f);

	for(int i=0 ; i<plants.size() ; i++){
		if(plants[i]->isDead()){
			plants[i]->makeCellEmpty();
			delete plants[i];
			plants.erase(plants.begin() + i);
		}
	}

	for(auto plant :plants){
		plant->update();
		if(plant->isHaveSun()){
			Sun* newSun = new Sun(0);
			sf::Vector2f posOfSun = plant->getSunPos();
			newSun->setPosition(posOfSun.x , posOfSun.y);
			this->suns.push_back(newSun);
		}

		if(plant->isHaveRegularPea() && this->isZombiAreInLineOf(plant)){
			RegularPea* newPea = new RegularPea();
			sf::Vector2f posOfNewPea = plant->getPeaAddr();
			newPea->setPosition(posOfNewPea.x , posOfNewPea.y);
			this->projectiles.push_back(newPea);
		}
		if(plant->isHaveSnowPea() && this->isZombiAreInLineOf(plant)){
			IcyPea* newIcePea = new IcyPea();
			sf::Vector2f posOfNewPea = plant->getPeaAddr();
			newIcePea->setPosition(posOfNewPea.x , posOfNewPea.y);
			this->projectiles.push_back(newIcePea);
		}
		if(plant->isHaveWatermelon() && this->isZombiAreInLineOf(plant)){
			Watermelon* newWatermelon = new Watermelon();
			sf::Vector2f posOfNewWatermelon  = plant->getWatermelonAddr();
			newWatermelon->setPosition(posOfNewWatermelon.x , posOfNewWatermelon.y);
			newWatermelon->addStartPos(posOfNewWatermelon);
			sf:: Vector2f NearestZombieAddr = this->fineNearestZombie(plant,newWatermelon);
			newWatermelon->addEndPos(NearestZombieAddr.x - 50);
			this->Watermelons.push_back(newWatermelon);
		}
	}

	for(auto projectile : projectiles){
		projectile->move(1.f,0.f);
	}

	for(int i=0 ; i<projectiles.size() ; i++){
		if(projectiles[i]->isOffScreen(800) || projectiles[i]->isHit()){
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
		}
	}

	for(int i=0 ; i<zombies.size();i++){
		zombies[i]->upDate();
		if(zombies[i]->isDead()){
			delete zombies[i];
			zombies.erase(zombies.begin() + i);			
		}
	}

	for(int i=0 ; i<Watermelons.size();i++){
		float x = abs(Watermelons[i]->middleOfDistance() - Watermelons[i]->position().x);
		float y = sqrt(pow(Watermelons[i]->middleOfDistance(), 2) - pow(x ,2));
		float dy = abs(Watermelons[i]->middleOfDistance() - y);
		float newY = Watermelons[i]->getStartPos().y + dy - 0.5f * Watermelons[i]->getSprite().getLocalBounds().height;
		Watermelons[i]->setPosition(Watermelons[i]->position().x, newY);
		Watermelons[i]->move(3,0);
		if(Watermelons[i]->position().x >= Watermelons[i]->getEndPos()){
			Watermelons[i]->giveDamage();
			delete Watermelons[i];
			Watermelons.erase(Watermelons.begin() + i);				
		}
	}

	this->checkZombiePlantCollision();
	this->updateMousePositions();
	this->updateSuns();
	this->checkZombiePeaCollision();
}

void Game::render()
{
	this->window->clear();
	this->ShowBackGround(BACK_GROUND_PATH);
	this->showSunsNum();
	this->clearDownSun();
	if(!isDone && !isGameOver){
		for(auto plant : plants){
			if(plant->itWatermelon)
				plant->render(*this->window);
		}
		for(auto plant : plants){
			if(!plant->itWatermelon)
				plant->render(*this->window);
		}
		for(auto zombie : this->zombies)
			zombie->render(*this->window);
		for(auto sun : this->suns)
			sun->render(*this->window);
		for(auto projectile :projectiles)
			projectile->render(*this->window);
		for(auto watermelon : Watermelons)
			watermelon->render(*this->window);
    }

	this->sunFlowerPriceRectangle->render(*this->window);
	this->walnutPriceRectangle->render(*this->window);
	this->regularPeaShooterPriceRectangle->render(*this->window);
	this->icyPeaShooterPriceRectangle->render(*this->window);
	this->watermelonShooterPriceRectangle->render(*this->window);

	if(!isGameOver){
		this->showRound();

		this->addNewSunFlower();
		this->addNewWalnut();
		this->addNewRegularPeaShooter();
		this->addNewIcyPeaShooter();
		this->addNewWatermelonShooter();
	}

	if(isDone){
		this->showWonState();
	}

	if(isGameOver){
		this->ShowGameOverPic();
	}

	this->window->display();
}
