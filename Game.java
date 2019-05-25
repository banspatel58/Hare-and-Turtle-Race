// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// banspate
import java.util.Random;
import java.io.*;

public class Game{
	
	public static void main (String args[]){
		System.out.println( " Welcome to the CSCI 240 Game of Horse! " );
		
		Player Player1 = new Player("Player#1", 0);
		Player Player2 = new Player("Player#2", 0);
		
		System.out.print( Player1.toString());
		Player1.makeHit();
		System.out.print( Player2.toString());
		Player2.makeHit();
		
		//Player1.playerScore();
		//Player2.playerScore();
		
		if (Player1.makeHit() == 1 && Player2.makeHit() == 2){
			System.out.println( Player2.toString() + ": Added an " + Player2.playerScore() );
		}else{
			System.out.println( " Valid " );
		}
	}
}
//+ this.makeHit() 