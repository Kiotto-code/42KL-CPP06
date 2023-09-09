if [ $# -eq 0 ]; then
	find . -name "Makefile" -exec rm -rf {} \;
else
	find . -name "$1" -exec rm -rf {} \;