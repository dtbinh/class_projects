use strict;
use warnings;
use Data::Dumper;

my $str; # holds the complete string
my %hash;
# takes in all lines of code
open(IN, '<:encoding(UTF-8)', $ARGV[0]) or die "Could not open file '$ARGV[0]' $!\n";
# skips first line
while (<IN>) {
	if ($_ =~ /^>/){
		next;
	}
    chomp;
    # concatinates with string
    $str .= $_;
}
# closes input
close(IN);

# length of input -1 to cover for use of 0 as a position
# takes in an argument to take various sized mers
my $l_size = length($str) - ($ARGV[1]-1);
# itirates through the string for values
for (my $i = 0; $i < $l_size; $i++) {
	# if a vaule is new it is initiated with a 1 value
	# if there is a repete it has 1 added to its count
	$hash{ substr($str, $i, $ARGV[1]) }++;
}

# searches for unique mers
my $unique = grep { $_ == 1 } values %hash;

# opens output file
open OUT, ">output.txt" or die "Error opening output.txt: $!\n";
# prints number of uniques
print OUT "Number of unique keys: ". $unique."\n";
# prints out the hash table and its vales
print OUT Dumper(\%hash);
# closes output stream
close OUT;