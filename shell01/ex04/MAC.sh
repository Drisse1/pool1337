#!/bin/sh
ifconfig | grep "\sether" | cut -d ' ' -f2
