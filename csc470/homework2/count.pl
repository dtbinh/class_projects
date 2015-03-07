use strict;
use warnings;
use Data::Dumper;

my $str; # holds the complete string
# takes in all lines of code
open(IN, '<:encoding(UTF-8)', $ARGV[0]) or die "Could not open file '$ARGV[0]' $!\n";
# skips first line
while (<IN>) {
    chomp;
    # concatinates with string
    $str .= $_;
}
# closes input
close(IN);

my %hash = ('A' => 4, 'R' => 6, 'N' => 2, 'D' => 2, 'B' => 0, 'C' => 2, 'Q' => 2, 'E' => 2, 'Z' => 0, 'G' => 4, 'H' => 2, 'I' => 3, 'L' => 6, 'K' => 2, 'M' => 1, 'F' => 2, 'P' => 4, 'S' => 4, 'T' => 4, 'W' => 1, 'Y' => 2, 'V' => 4);
# length of input -1 to cover for use of 0 as a position
# takes in an argument to take various sized mers
my $total = 0;
my $l_size = length($str) - 1;
# itirates through the string for values

$total = $hash{(substr($str, 0, 1))};
for (my $i = 1; $i < $l_size; $i++) {
	# searches for unique mers
	$total = $total * $hash{(substr($str, $i, 1))};
}
# opens output file
open OUT, ">output.txt" or die "Error opening output.txt: $!\n";
# prints number of uniques
print OUT "Number of possible patterns: ".$total."\n";
# prints out the hash table and its vales
print OUT Dumper(\%hash);
# closes output stream
close OUT;