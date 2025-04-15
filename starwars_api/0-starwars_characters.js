#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Unable to fetch movie data (status code: ${response.statusCode})`);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  const printCharacter = (index) => {
    if (index >= characters.length) {
      return;
    }

    request(characters[index], (charError, charResponse, charBody) => {
      if (charError) {
        console.error(charError);
        return;
      }

      if (charResponse.statusCode !== 200) {
        console.error(`Error: Unable to fetch character data (status code: ${charResponse.statusCode})`);
        return;
      }

      const characterData = JSON.parse(charBody);
      console.log(characterData.name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
