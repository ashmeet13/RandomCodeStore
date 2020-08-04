// Daniel Shiffman
// http://codingtra.in
// http://patreon.com/codingtrain

console.log('background running');

chrome.runtime.onMessage.addListener(receiver);

window.word = '<PlaceHolder>';

// Recieves Message From Content. Defines Global so that PopUp can read.
function receiver(request, sender, sendResponse) {
  console.log(request);
  word = request.text;
}
