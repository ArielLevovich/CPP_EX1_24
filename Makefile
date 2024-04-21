CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wall -Wextra
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

run: demo
	./$^

demo: Demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) $^ -o test

 # Note: clang-tidy removed since it's specific to Clang. Consider using cppcheck or another tool if needed.
tidy:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test
