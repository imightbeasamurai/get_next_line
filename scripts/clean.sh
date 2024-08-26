#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

rm next

if [ $? -eq 0 ]; then
	echo -e "${GREEN}Executable removed!${NC}"
else
	echo -e "${RED}Executable NOT removed!${NC}"
fi