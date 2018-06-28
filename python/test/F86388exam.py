#!/usr/bin/python
# -*- coding: utf-8 -*-

from urllib import urlopen
from urllib import quote
import sys


def print_tags(page):
    print('===TAGS===')

    for tag in page.split('<tag-list')[1].split('</name>'):
        if 'name' in tag:
            print tag.split('<name>')[1]


def print_works(page):
    print('===WORKS===')

    for work in page.split('<work-list')[1].split('<title>')[1:]:
        print work.split('</title>')[0]


def download_page(name):
    page = urlopen('http://musicbrainz.org/ws/2/artist/?query=artist:' +
                   quote(name)).read()
    artist_page = page.split('<artist')[2]
    print_tags(artist_page)

    artist_id = artist_page.split('"')[1]
    page = urlopen('http://musicbrainz.org/ws/2/artist/' + artist_id +
                   '?inc=works').read()
    print_works(page)


try:
    download_page(sys.argv[1])
except IndexError:
    print "No arguments"
