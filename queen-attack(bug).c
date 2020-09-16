#include <stdio.h>

int main(void) {
  int n,k,r_q,c_q;
  int obs[k][2];//obstacles 2D array
  int r,c;
  int cp,cn,rp,rn,d1r,d2r,d3r,d4r,d1c,d2c,d3c,d4c;
  int attack = 0;
  int i,j;

  start:
  //inputs of n and obstacles' numbers k
  scanf("%d %d",&n,&k);
  //sanitizing values of n & k
  if(n<1 || k > n*n || k<0) goto start;
  //inputs of queen's position
  scanf("%d %d",&r_q,&c_q);
  //sanitizing values of r_q & c_q
  if(r_q<1 || r_q>n || r_q<1 || r_q>n) goto start;

  //attacks without obstacles
  if(k == 0){
	  attack = 2*(n-1);

	  for(i = r_q-1,j=c_q-1; i>0 && j>0; i--,j--) attack++;
	  for(i = r_q-1,j=c_q+1; i>0 && j<=n; i--,j++) attack++;
	  for(i = r_q+1,j=c_q-1; i<=n && j>0; i++,j--) attack++;
	  for(i = r_q+1,j=c_q+1; i<=n && j<=n; i++,j++) attack++;
  }
  else{
    //inputs of obstacles position
    cp = n+1;
    cn = 0;
    rp = n+1;
    rn = 0;
    d1r = 0;
    d1c = 0;
    d2r = 0;
    d2c = n+1;
    d3r = n+1;
    d3c = 0;
    d4r = n+1;
    d4c = n+1;
    
    for(i = 0; i<k; i++){
      scanf("%d %d",&r,&c);
      //sanitizing obstacles postion(including queen's position)
      if(r<1 || r>n || r == r_q || c<1 || c>n || c == c_q){
        goto start;
      }
      
      if(r==r_q && c>c_q && c<cp) cp = c;
      else if(r==r_q && c<c_q && c>cn) cn = c;
      else if(c==c_q && r>r_q && r<rp) rp = r;
      else if(c==c_q && r<r_q && r>rn) rn = r;
      else if(r<r_q && c<c_q && r_q-r == c_q-c && r>d1r) d1r=r,d1c=c;
      else if(r<r_q && c>c_q && r_q-r == c-c_q && r>d2r) d2r=r,d2c=c;
      else if(r>r_q && c<c_q && r-r_q == c_q-c && r<d3r) d3r=r,d3c=c;
      else if(r>r_q && c>c_q && r-r_q == c-c_q && r<d4r) d4r=r,d4c=c;  
        
      obs[i][0] = r;
      obs[i][1] = c;
    }
    
    for(i=cn+1; i<cp; i++) result++;
    for(i=rn+1; i<rp; i++) result++;
    for(i=d1r+1, j=d1c+1; i<d4r && j<d4c; i++,j++) result++;
    for(i=d2r+1, j=d2c-1; i<d3r && j>d3c; i++,j--) result++;
    
    result = result - 4;
  }

  printf("%d",attack);

  return 0;
}
