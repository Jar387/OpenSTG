#!/usr/bin/sh
indent -linux -npro src/*
indent -linux -npro include/*
rm -f src/*~
rm -f include/*~
