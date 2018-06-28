#!/usr/bin/python
# -*- coding: utf-8 -*-
from urllib import urlopen

webpage = urlopen('http://sinoptik.bg/sofia-bulgaria-100727011?location')

for l in webpage:
    if '<meta property="og:description" content=' in l:
        lft=l.find('Времето')
        rght=l.find('Подробна')
        weather=l[lft:rght]
        print weather
        break
