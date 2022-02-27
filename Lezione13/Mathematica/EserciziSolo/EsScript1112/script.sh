#!/bin/bash

ps -u root | grep crond | cut -f 1 -d?
