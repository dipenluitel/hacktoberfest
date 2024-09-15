/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com;

/**
 *
 * @author zenalarifin
 */
import java.util.Scanner;

public class Program{
    
public static void main(String[] args){
Scanner in = new Scanner(System.in);
Stack s1 = new Stack();
int opt = 0;

do{ 
System.out.println("Choose an option:" + "\n" +
"1) Add item \n" + 
"2) Del item \n" + 
"3) Show Items \n" +
"4) Stack lenght \n" +
"5) Exit \n");

opt = in.nextInt();

switch(opt){
case(1):
System.out.println("[++] Put the number to add:");
int val = in.nextInt();
s1.add_Node(val);
break;
case(2):
s1.del_Node();
break;
case(3):
s1.show_Nodes();
break;
case(4):
s1.stack_Lenght();
break;
}



}while(opt != 5);

System.exit(0);
   
}


}

class Stack{
    
public Node last_node; 
int lenght;

public Stack(){
last_node = null;
lenght = 0;
}
   
public void add_Node(int value){
Node new_node = new Node(value);
new_node.previous = last_node;
last_node = new_node;
lenght++;
}

public void del_Node(){
int temp = last_node.value;

last_node = last_node.previous;
System.out.println("> Item: " + temp + " deleted!");
}


public void show_Nodes(){
Node temp = last_node;
String list = "";

while(temp!=null){
list += temp.value + "\n";
temp = temp.previous;
}

System.out.println(list);
}

public int stack_Lenght(){
return lenght;
}
    
 
}

class Node{
public Node previous;
int value;

public Node(int value){
this.value = value;
previous = null;
}


}
