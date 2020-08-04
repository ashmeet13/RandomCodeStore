// Wordnik API key:
// let api_key = '/?api_key=48dd829661f515d5abc0d03197a00582e888cc7da2484d5c7'

function setup() {
  noCanvas();

  let bgpage = chrome.extension.getBackgroundPage();
  let word = bgpage.word.trim();

  let url = `https://flask-wala-app.herokuapp.com/parse`;
  let send_data = {
    'name':word
  };
  // console.log(send_data)
  httpPost(url, send_data, gotData)

  function gotData(data) {
    let test = JSON.parse(data);
    console.log(typeof test)
    createP(test.message).style('font-size', '12pt');
  }

  //createP(word);
}
