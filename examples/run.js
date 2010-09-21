
/**
 * Module dependencies.
 */

var md = require('../build/default/markdown')
  , fs = require('fs');

fs.readFile(__dirname + '/example.md', 'utf8', function(err, str){
  console.log(md.parse(str));
});