/** topcoder problem 
 * FloorBoards: https://community.topcoder.com/stat?c=problem_statement&pm=8397&rd=10806 
**/

import java.math.*;

public class FloorBoards {

	int w, h, inf = Integer.MAX_VALUE;
	boolean[][] blocked;
	Integer[][][][] memoization;
	
	int dp(int board, int i, int j, int mask) {
		if(i == w) {
			return dp(0, 0, j+1, mask);
		} 
		if(j == h) {
			return 0;
		}
		if(memoization[board][i][j][mask] != null) {
			return memoization[board][i][j][mask];
		}
		
		int res = inf;
		int missingVerticalBoard = ((1 << w) - 1 - (1 << i)) & mask; //turn off ith bit
		
		if(blocked[i][j]) {
			res = dp(0,i+1, j, missingVerticalBoard);
		} else {
			if(board == 1) { //continue horizontal board
				res = Math.min(res,  dp(board, i+1, j, missingVerticalBoard)); //eliminate the column behind
			} if((mask & (1 << i)) > 0) { //continue vertical board
				res = Math.min(res, dp(0, i+1, j, mask));
			}
			//start  new board
			res = Math.min(res,  1 + dp(1, i+1, j, missingVerticalBoard)); //new horizontal
			res = Math.min(res,  1 + dp(0, i+1, j, missingVerticalBoard | (1 << i))); //new vertical;
		}
		
		return memoization[board][i][j][mask] = res;
	}
	
	public int layout(String[] room) {
		h = room.length;
		w = room[0].length();
		
		memoization = new Integer[2][w][h][1<<w]; //start with a board in the first cell
		blocked = new boolean[w][h];
		for(int i=0; i<w; i++) {
			for(int j=0; j<h; j++) {
				blocked[i][j] = room[j].charAt(i) == '#';
			}
		}
		return dp(0, 0, 0, 0);
	}
}
