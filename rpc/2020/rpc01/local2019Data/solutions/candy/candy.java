// Arup Guha
// 8/18/2019
// Solution to 2019 UCF Locals Problem: Candyland

import java.util.*;

public class candy {

	final public static String SPECIAL = "SPECIAL";

	// Manages the board.
	public static int numPlayers;
	public static int numSq;
	public static String[] board;
	public static HashMap<String,Integer> special;
	
	// Manages cards.
	public static int numCards;
	public static int[] cardType;
	public static String[] cards;
	
	// Manages the players.
	public static int[] loc;
	
	public static void main(String[] args) {
	
		// Read in the basic parameters.
		Scanner stdin = new Scanner(System.in);
		numSq = stdin.nextInt();
		numPlayers = stdin.nextInt();
		board = new String[numSq-1];
		special = new HashMap<String,Integer>();
		
		// Read in the board, store special square map.
		for (int i=0; i<numSq-1; i++) {
			board[i] = stdin.next();
			if (board[i].length() > SPECIAL.length() && board[i].substring(0,SPECIAL.length()).equals(SPECIAL))
				special.put(board[i], i);
		}
		
		// Read in the cards.
		numCards = stdin.nextInt();
		cardType = new int[numCards];
		cards = new String[numCards];
		for (int i=0; i<numCards; i++) {
			cardType[i] = stdin.nextInt();
			cards[i] = stdin.next();
		}
		
		// Initial game status.
		loc = new int[numPlayers];
		Arrays.fill(loc, -1);
		int curP = 0;
		int curCard = 0;
		
		int res = -1;
		int turns = 1;
		
		// We'll break out when someone wins.
		while (true) {
			
			// Do this player's turn.
			doTurn(curP, curCard);
			
			// Winner winner chicken dinner!!!
			if (loc[curP] == numSq-1) {
				res = curP+1;
				break;
			}
			
			// Next player, next card.
			curP = (curP+1)%numPlayers;
			curCard = (curCard+1)%numCards;
			turns++;
		}
		
		// Ta da!
		System.out.println(curP+1);
	}
	
	public static void doTurn(int curP, int curCard) {
		
		// Move to the next square of this color.
		if (cardType[curCard] == 1) {
			
			// Advance till we hit the color or the end of the board.
			loc[curP]++;
			while (loc[curP] < board.length && !board[loc[curP]].equals(cards[curCard])) loc[curP]++;
		}
		
		// Move ahead two squares of this color.
		else if (cardType[curCard] == 2) {
			
			for (int i=0; i<2; i++) {
				loc[curP]++;
				while (loc[curP] < board.length && !board[loc[curP]].equals(cards[curCard])) loc[curP]++;
				if (loc[curP] == numSq-1) break; // Get out if we already won.
			}
		}
		
		// Just move the player directly to this square (not a winning square)
		else {
			loc[curP] = special.get(cards[curCard]);
		}
	}
}
