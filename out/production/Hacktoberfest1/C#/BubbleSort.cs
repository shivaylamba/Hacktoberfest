public static int[] BubbleSort(int[] arr)
{
    int length = arr.Length;
    int temp = arr[0];
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;        
}
