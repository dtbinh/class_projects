use List::Util qw(min);
use strict;
use warnings;

print levenshtein('GGATTGGGGACCCTACCTAGCCGAGATAACTGTTGAAAGTTTCTTATTGCGGGGATTTGAAGAGGCAGGGGTTAGTTTCGAGGTGAATTAGAACCAATTTTATTTTTTTTTAGGCATTTCTGAACTTTATGAAATCTATGTCGCCCCGGCCCCCACGGGCACCACCTATCTGTCTGTGCCAACCGTTACCAGGCTGCTGATTCCAGTAGCCGGTGATAACTGAGCTGGAGATGTTTGTGTGAATGGAGGTCCACAATGATTAAATGCTGAACTCCGATAAGGAAGGTTGAACATTTACGAGCCGAAAGAGGGGATAATAAGAGTGGAATTTC', 'MKRNVVVAGLFGLLLALGWLVSAGEAMAQPVPGGSYLNSCNNVQVRRGRDLTAFCATRRGNWVQTRLNDFPSCRGDISNQDGQLWCVRGRPLPPPPAPGPQPLPPGSYQRSCRNAFVGPDNVLRAQCRAGGHVWIPAAVNLRYCWGARDIANFNGQLTCTR');
 
sub levenshtein {
    my ($str1, $str2) = @_;
    my @ar1 = split //, $str1;
    my @ar2 = split //, $str2;
 
    my @dist;
    $dist[$_][0] = $_ foreach (0 .. @ar1);
    $dist[0][$_] = $_ foreach (0 .. @ar2);
 
    foreach my $i (1 .. @ar1){
        foreach my $j (1 .. @ar2){
            my $cost = $ar1[$i - 1] eq $ar2[$j - 1] ? 0 : 1;
            $dist[$i][$j] = min(
                        $dist[$i - 1][$j] + 1, 
                        $dist[$i][$j - 1] + 1, 
                        $dist[$i - 1][$j - 1] + $cost );
        }
    }
 
    return $dist[@ar1][@ar2];
}