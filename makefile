all: arraySorter triAnimate windowMaker

arraySorter: Array\ Sorter/arraySorter.cpp
	@echo "\nCompiling Array Sorter..."
	@g++ Array\ Sorter/arraySorter.cpp -o arraySorter -lncurses
	@sleep 0.25
	@echo "Moving into bin folder"
	@mv arraySorter bin/

triAnimate: Triangle\ Animate/triAnimate.cpp
	@sleep 0.25
	@echo "\nCompiling Triangle Animator..."
	@g++ Triangle\ Animate/triAnimate.cpp -o triAnimate -lncurses
	@echo "Moving into bin folder"
	@mv triAnimate bin/

windowMaker: Window\ Maker/windowMaker.cpp
	@sleep 0.25
	@echo "\nCompiling Window maker..."
	@g++ Window\ Maker/windowMaker.cpp -o windowMaker -lncurses
	@echo "Moving into bin folder"
	@mv windowMaker bin/
