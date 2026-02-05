c
	
	printf("enter the value for second matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
			c[i][j]=0;
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for (k=0;k<3;k++) {
				c[i][j]+=a[i][k]*b[j][k];
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		 {
			printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	
	return 0;
}
