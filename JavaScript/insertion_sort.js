var _testObj = {
    numStorage : new Array(2, 34, 4, 0, 234, 5),

    getSort: function(data) {
        var i,j;
        for(i = 1; i < data.length; i++)
        {
            over = data[i]; 
             
            for(j = i-1; j >= 0 && data[j] > over; j--) 
            {
                data[j+1] = data[j];
            }
            data[j+1] = over;
        }
        //возвращаем обработанный массив
	    return data;
    }
};

alert(_testObj.getSort(_testObj.numStorage));


