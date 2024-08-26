#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

gcc *.c -o next

if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compiled successfully${NC}"
    ./next "$@"
else
    echo -e "${RED}Did not compile${NC}"
fi