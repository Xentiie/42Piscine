#!/usr/bin/perl

use warnings;
use strict;

die "program x y density empty rock full" unless (scalar(@ARGV) == 6);

my ($x, $y, $density, $empty, $rock, $full) = @ARGV;

print "$y$empty$rock$full\n";
for (my $i = 0; $i < $y; $i++) 
{
    for (my $j = 0; $j < $x; $j++) 
    {
        if (int(rand($y) * 2) < $density) 
        {
            print $rock;
        }
        else 
        {
            print $empty;
        }
    }
    print "\n";
}