CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a

OBJS = Zombie.o Game.o main.o HairMetalZombie.o RegularZombie.o sun.o Board.o Cell.o \
SunFlowerPriceRectangle.o WalnutPriceRectangle.o RegularPeaShooterPriceRectangle.o icyPeaShooterPriceRectangle.o \
Plants.o Sunflower.o Walnut.o IcyPeaShooter.o RegularPeaShooter.o RegularPea.o IcyPea.o Projectiles.o\
WatermelonShooterPriceRectangle.o WatermelonShooter.o Watermelon.o
HEADERS = Zombie.h Game.h HairMetalZombie.h RegularZombie.h sun.h Board.h Cell.h \
SunFlowerPriceRectangle.h WalnutPriceRectangle.h RegularPeaShooterPriceRectangle.h icyPeaShooterPriceRectangle.h \
Plants.hpp Sunflower.hpp Walnut.hpp IcyPeaShooter.hpp RegularPeaShooter.hpp RegularPea.hpp IcyPea.hpp Projectiles.hpp \
WatermelonShooterPriceRectangle.h WatermelonShooter.hpp Watermelon.hpp

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: pvz clean

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

pvz: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o
