<HTML>
<HEAD>
<TITLE>SOAP Brownfield Location</TITLE>
<SCRIPT Language="JavaScript">
<!--//
function Search(loc){
	if (loc.location_input.value == "")
		alert("Please enter an address.")
	else
		alert("Here are your results for location " + loc.location_input.value)
		
}
//-->
</SCRIPT>
</HEAD>
<BODY>
<FORM NAME="add_location">
	Add in Location: <INPUT TYPE="text" name="location_input">
	<input type="submit" value="Search" onClick="Search(this.form)"><br>
</FORM>
</BODY>
</HTML>	
