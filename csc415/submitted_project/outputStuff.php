<html>
<body>

Latitude: <?php echo $_POST["lat"]; ?><br>
Longitude: <?php echo $_POST["lng"]; ?><br>


<?php
$array = array(
        0 => $_POST["lat"],
        1 => $_POST["lng"],
//        2 => $_POST["zip"],
//        3 => $_POST["state"],
);


$lat = $_POST["lat"];
$lng = $_POST["lng"];
//$command = 'C:\\mypath1\\mypath2\\run '.$lat.' '.$lng;
//$command = 'run '.$lat.' '.$lng;
$command = 'java IEEE_Floats '.$lat.' '.$lng;
echo $command;

//echo exec('run', $output, $return);
exec($command, $output, $return);
//exec($command);
echo " Output: ";
echo $output;
echo " Return: ";
echo $return;
var_dump($output);

/*$adapter = new \Geocoder\HttpAdapter\CurlHttpAdapter();

// Create a chain of providers.
// Be sure to include my previously created adapter.
$chain = new \Geocoder\Provider\ChainProvider(
    array(
        new \Geocoder\Provider\GoogleMapsProvider($adapter),
    )
);

// Instantiate the geocoder.
$geocoder = new \Geocoder\Geocoder();

// Register my providers.
$geocoder->registerProvider($chain); */

function concat($a, $c){

        $newConcat = $a . " " . $c;
        return $newConcat;
}        

/*foreach ($locations as $key => $value) {
    // Try to geocode.
    try {
        $geocode = $geocoder->geocode($value['address']);
        $longitude = $geocode->getLongitude();
        $latitude = $geocode->getLatitude();

    } catch (Exception $e) {
        echo $e->getMessage();
    }
} */

//$addrString = concat($array[0], $array[1]);
//, $array[2], $array[3]);
//echo $addrString; 

 
?>

</body>
</html>
