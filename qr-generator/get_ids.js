
const fs = require ('fs');
const path = require ('path');

var jsonDir = "json";
var csvDir = "csv";

processFile (jsonDir + "/shared_links.json");

function processFile (jsonFile)
{
	var outputs = {};
	var files = process.argv;
	files.forEach ((val, aidx) => { if (aidx > 1) outputs [aidx] = ""; });
	
	var data = fs.readFileSync (jsonFile);
	var result = JSON.parse (data);
	result.links.forEach ((item) => {
		files.forEach ((val, aidx) => {
			if (aidx > 1 && item.url.indexOf (val) >= 0)
				outputs [aidx] += item.url + '\n';
		});
	});
	files.forEach ((val, aidx) => {
		if (aidx > 1)
			fs.writeFileSync (csvDir + '/' + path.basename (val) + ".csvfrag", outputs [aidx]);
	});
}
