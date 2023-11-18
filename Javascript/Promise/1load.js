/*
function loadScript(src, callback) {
	let script = document.createElement('script');
	script.src = src;

	script.onload = () => callback(null, script);
	script.onerror = () => callback(new Error(`Script load error for ${src}`));

	document.head.append(script);
}
*/

function loadScript(src) {
	return new Promise(function (resolve, reject) {
		let script = document.createElement('script');
		script.src = src;

		script.onload = () => resolve(script);
		script.onerror = () => reject(new Error(`Script load error for ${src}`));

		document.head.append(script);
	});
}


let promise = loadScript("https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.17.11/lodash.js");

promise.then(
	script => {console.log(script.src)},
	error => console.log(error.message)
);

promise.then(
	script => { console.log("Another handler...") }
);