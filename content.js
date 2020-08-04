window.addEventListener('click', testing);

console.log("!! ~~ Here");



function testing(){
  console.log("!! ~~ Inside");
  let all_messages = document.getElementsByClassName("eRacY");
  let last_message = all_messages[all_messages.length-1].innerText
  
  let message_to_background = {
          text: last_message
        };

  console.log(message_to_background)

  chrome.runtime.sendMessage(message_to_background);
}


// function wordSelected() {
//   let selectedText = window
//     .getSelection()
//     .toString()
//     .trim();
//   console.log(selectedText);
//   if (selectedText.length > 0) {
//     let message_to_background = {
//       text: selectedText
//     };
//     chrome.runtime.sendMessage(message_to_background);
//   }
// }


