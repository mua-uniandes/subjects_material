/**
 * Problem from the internal UCF: Reach for the Stars
 * https://lpc.ucfprogrammingteam.org/localFiles/local2015Problems.pdf
 **/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Stars {
 	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int cases=1; cases<=t; cases++) {
			String[] l = br.readLine().split(" ");
			int r = Integer.parseInt(l[0]);
			int c = Integer.parseInt(l[1]);
			boolean[][] isMarked = new boolean[r][c];
			boolean[][] canMark = new boolean[r][c];
			
			for(int i=0; i<r; i++) {
				String cells  = br.readLine();
				for(int j=0; j<c; j++) {
					isMarked[i][j] = cells.charAt(j) == '#';
				}
			}
			
			//precompute where the marks can be
			for(int i=1; i<r-1; i++) {
				for(int j=1;j<c-1; j++) {
					canMark[i-1][j] = isMarked[i-1][j] && isMarked[i][j] && isMarked[i+1][j] && 
							          isMarked[i][j-1] && isMarked[i][j+1];
				}
			}
			
			int stampmask = 1 | (1 << c) | (1 << (c-1)) | (1 << (c+1)) | (1 << (2*c));
			int[][] state = new int[r*c+1][1 << (2*c)];
			
			for(int[] dd : state) {
				Arrays.fill(dd, Integer.MAX_VALUE);
			}
			
			state[0][0] = 0; //basecase
			int currCell = -1;
			for(int i=0; i<r; i++) {
				for(int j=0; j<c; j++) {
					currCell ++;
					//loop through masks and update position i+i
					for(int m=0; m< (1 << 2*c); m ++) {
						if(state[currCell][m] < Integer.MAX_VALUE) {
							//markcell
							if(canMark[i][j]) {
								int nextMask = (m | stampmask) >> 1; //rolling mask!
								state[currCell+1][nextMask] = Math.min(state[currCell+1][nextMask], state[currCell][m]+1);
							}
							//dont mark
							//only mark things that are in front
							if(!isMarked[i][j] || ((m & 1) > 0)) {
								int nextMask = m >> 1;
								state[currCell+1][nextMask] = Math.min(state[currCell][nextMask], state[currCell][m]);
							}
						}
					}
				}
			}
			String res = "impossible";
			if(state[r*c][0] < Integer.MAX_VALUE) { //nothing is marked
				res = String.format("%d", state[r*c][0]);
			}
			System.out.printf("Image #%d: %s%n", cases, res);
		}
	}
}
