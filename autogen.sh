#!/bin/sh

aclocal -I m4
autoreconf --force --install -I config -I m4

