#1/bin/sh -e

# define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' #no color

BASEDIR=$(realpath "$(dirname "$0")")
BASEDIR=$(realpath "$BASEDIR/..")
BUIDDIR=$ROOTDIR/build
print_header() {
	echo "${YELLOW}####################################${NC}"
	echo "${YELLOW}### ${1}${NC}"
	echo "${YELLOW}####################################${NC}"

}

print_step() {
	echo "${BLUE}[ * ] ${1}${NC}"
}

print_success() {
        echo "${GREEN}[ V ] ${1}${NC}"
}

print_error() {
        echo "${RED}[ X ] ${1}${NC}"
}



if [ "$1" = "clean" ]; then
	print_header "Clean no previous build"
	if [ -d "$BUILDDIR" ]; then
		print_step "Removing $BUILDDIR directory..."
		rm -rf "$BUILDDIR"
		print_success "Removed $BUILDDIR directory."
	else
		print_success "No priveous build found."
	fi
fi

print_header "Configure the project"
print_step "Running Cmake in $BUILDDIR..."

cmake -S "$ROOTDIR" -B "$ROOTDIR/build"
ret=$?


if [ $ret -eq 0 ]; then
	print_success "Completed successfully."
else
	print_error "CMake configuration failed."
	exit 1
fi

print_header "Building the project"
print_step "Buiding the project in $BUILDDIR"

cmake --build "$BUILDDIR"

ret=$?

if [ $ret -eq 0 ]; then
        print_success "Builded successfully."
else
        print_error "BUild  failed."
        exit 1
fi


