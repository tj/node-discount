
var assert = require('assert'),
    fs = require('fs'),
    markdown = require('./build/markdown')

assert.ok(markdown.version.match(/^\d+\.\d+\.\d+$/), 'version is improperly formatted')
assert.equal(fs.readFileSync('test/test.html'), markdown.parse(fs.readFileSync('test/test.md')))