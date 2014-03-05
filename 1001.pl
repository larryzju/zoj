#!/usr/bin/env perl

use strict;
use warnings;

while (<STDIN>)
{
    chomp;
    if ( /(\d+)\s(\d+)/ )
    {
        printf "%d\n", $1 + $2;
    }
}
