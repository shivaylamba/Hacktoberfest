package com.company.Lec9;

public class Mazepath {
    public static void maze(String pro,int row,int col)
    {
        if(row==1 && col==1)
        {
            System.out.println(pro);
            return;
        }
        if(row>1)
        {
            maze(pro+'V',row-1,col);
        }
        if(col>1)
        {
            maze(pro+'H',row,col-1);
        }
    }

    public static void main(String[] args) {
        maze("",3,3);
    }
}
