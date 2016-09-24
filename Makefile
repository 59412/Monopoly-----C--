CXX = g++-5
CXXFLAGS = -std=c++14 -Wreorder
EXEC = watopoly
OBJECTS = main.o academic.o building.o coop.o dctim.o  goose.o gototim.o gym.o map.o needles.o nonPropertySqr.o osap.o player.o propertySqr.o residence.o slc.o  tuition.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
