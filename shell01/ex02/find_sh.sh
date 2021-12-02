#!/bin/bash
find . -type f -name "*.sh" -exec basename {} \; | awk -F'.' '{print $1}'
