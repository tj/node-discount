
var assert = require('assert')
  , fs = require('fs')
  , markdown = require('./build/default/markdown');

assert.ok(markdown.version.match(/^\d+\.\d+\.\d+$/), 'version is improperly formatted')
assert.equal(
    fs.readFileSync('test/test.html', 'utf8')
  , markdown.parse(fs.readFileSync('test/test.md', 'utf8'))
  );

console.log('all good');