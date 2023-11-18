let promise = new Promise((resolve, reject) => {
	// 当 promise 被构造完成时，自动执行此函数
	
	// 1 秒后发出工作已经被完成的信号，并带有结果 "done"
	setTimeout(() => resolve("done"), 1000);


});

// resolve 运行 .then 中的第一个函数
promise.then(

	/**
	 * 消费者
 	*/


	result => { console.log(result); }, // 1 秒后显示 "done!"
	error => { console.log(error); } // 不运行
);


