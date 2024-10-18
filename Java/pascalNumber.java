class Solution {

    private int function(int n, int r){
        long res=1;
        for(int i=0; i<r; i++){
            res*=(n-i);
            res/=(i+1);
        }
        return (int) res;
    }


    private void addRow(int row, List<List<Integer>> answer){
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<=row; i++){
            list.add(function(row, i));
        }
        answer.add(list);
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>();
         // The first "previous" row starts empty
         //answer.add(new ArrayList<>(1));
        for(int i=0; i<numRows; i++){
            addRow(i, answer);
        }
        return answer;
    }
}
