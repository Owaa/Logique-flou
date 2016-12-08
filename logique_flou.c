#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {

	char *nom ;
	float etat;
	float max, min;
	int id;

	
} modalite;

typedef struct {

	char *nom ;
	
	float angle;
	float vitesse;

	float max, min;
	float etat;
	int id;
	modalite modalite1;
	modalite modalite2;

	
} regle_t;


modalite getModalite( regle_t regle){

	modalite moda;

	moda.nom = regle.nom;
	moda.etat = regle.etat;
	moda.max = regle.max;
	moda.min = regle.min;

	return moda;


}




void CreatReagle (char * nom, float angle , float vitesse, int etat , int id, regle_t *regle, float max , float min){

	regle->nom = nom;
	regle->angle = angle;
	regle->vitesse = vitesse;
	regle->etat = etat;
	regle->id = id;

	regle->max = max;
	regle->min = min;

	
}

int valbetween( float val1 , float val2 , float valTest){
	
	if(valTest > val1 && valTest < val2)
		return 1;
	return 0;
	
}

float max ( float val1, float val2){


	return val1 > val2 ? val1 : val2;
}
float min ( float val1, float val2){


	return val1 < val2 ? val1 : val2;
}


int getIndexFromName(char * nom){

	if( strcmp(nom , "NM") == 0)
		return 0;
	if( strcmp(nom , "NS") == 0)
		return 1;
	if( strcmp(nom , "ZR") == 0)
		return 2;
	if( strcmp(nom , "PS") == 0)
		return 3;
	if( strcmp(nom , "PM") == 0)
		return 4;

	return -1;

}
/*
void returnAngleEval (float angle){

		//char regle[2][2];
	
	
	if( valbetween( -90 , -45 , angle) == 1){
			regle[nbRegle].nom   = "NM";
		 	regle[nbRegle].angle = angle;	
			regle[nbRegle].etat  = max(min(1,(-45-angle)/45),0);	
			nbRegle++;
	}
	if( valbetween( -60 , 0 , angle) == 1){
			regle[nbRegle].nom   = "NS";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min((angle+90)/45,(-angle)/45)   ,0);
			nbRegle++;
	}
	if( valbetween( -45 , 45 , angle) == 1){
			regle[nbRegle].nom   = "ZR";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min((angle+45)/45,(45-angle)/45)   ,0);
			nbRegle++;
	}
	if( valbetween( 0 , 90 , angle) == 1){
			regle[nbRegle].nom   = "PS";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min(angle/45,(-angle+90)/45),0) ;
			nbRegle++;
	}
	if( valbetween( 45 , 90 , angle) == 1){
			regle[nbRegle].nom   = "PM";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min(1,(angle-45)/45),0) ;
			nbRegle++;
	}
	
	//if(angle < 60 || angle > 60)
		//return nbRegle == 1 ? regle : NULL;
	//return nbRegle == 2 ? regle : NULL;
	
}

*/


float fctAppartenance ( float valeur,char *str){

	if( strcmp(str, "NM") == 0)
		return max(min(1,(-45-valeur)/45),0);

	if( strcmp(str, "NS") == 0)
		return max(min((valeur+90)/45,(-valeur)/45)   ,0);

	if( strcmp(str, "ZR") == 0)
		return max(min((valeur+45)/45,(45-valeur)/45)   ,0);

	if( strcmp(str, "PS") == 0)
		return max(min(valeur/45,(-valeur+90)/45),0) ;

	if( strcmp(str, "PM") == 0)
		return max(min(1,(valeur-45)/45),0) ;



}
int Evaluation (float angle, regle_t  *regle){

		//char regle[2][2];
	int nbRegle = 0;
	
	if( valbetween( -90 , -45 , angle) == 1){
			regle[nbRegle].nom   = "NM";
		 	regle[nbRegle].angle = angle;	
			regle[nbRegle].etat  = max(min(1,(-45-angle)/45),0);	
			regle[nbRegle].min = -90;
			regle[nbRegle].max = -45;
			nbRegle++;
	}
	if( valbetween( -90 , 0 , angle) == 1){
			regle[nbRegle].nom   = "NS";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min((angle+90)/45,(-angle)/45)   ,0);
			regle[nbRegle].min = -90;
			regle[nbRegle].max = 0;
			nbRegle++;
	}
	if( valbetween( -45 , 45 , angle) == 1){
			regle[nbRegle].nom   = "ZR";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min((angle+45)/45,(45-angle)/45)   ,0);
			regle[nbRegle].min = -45;
			regle[nbRegle].max = 45;
			nbRegle++;
	}
	if( valbetween( 0 , 90 , angle) == 1){
			regle[nbRegle].nom   = "PS";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min(angle/45,(-angle+90)/45),0) ;
			regle[nbRegle].min = 0;
			regle[nbRegle].max = 90;
			nbRegle++;
	}
	if( valbetween( 45 , 90 , angle) == 1){
			regle[nbRegle].nom   = "PM";
			regle[nbRegle].angle = angle;
			regle[nbRegle].etat  = max(min(1,(angle-45)/45),0) ;
			regle[nbRegle].min = 45;
			regle[nbRegle].max = 90;
			nbRegle++;
	}
	return nbRegle;
	//if(angle < 60 || angle > 60)
		//return nbRegle == 1 ? regle : NULL;
	//return nbRegle == 2 ? regle : NULL;
	
}





int main(){
	

	printf("\n--------------------------------------\n");
	printf("\n");

	
	regle_t regleResultat[4];
	regle_t tabRules[5][5];

	for(int i = 0; i != 5;i++)
		for(int j = 0; j != 5; j++)
			CreatReagle ( "ZZ" , 0, 0 , 0, 0, &tabRules[i][j], 0 , 0);



	

	CreatReagle ( "NM" , 0, 0 , 0, 0, &tabRules[0][2] , -45 , -90);
	CreatReagle ( "NS" , 0, 0 , 0, 0, &tabRules[1][1] , 0 , -90);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[1][3] , 45 , -45);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[2][2] , 45 , -45);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[3][1] , 45 , -45);
	CreatReagle ( "PS" , 0, 0 , 0, 0, &tabRules[3][3] , 90 , 0);
	CreatReagle ( "PM" , 0, 0 , 0, 0, &tabRules[4][2] , 90 , 45);

	regle_t regleAngle[2];
	regle_t regleVitesse[2];
	int nbRegleResultat = 0;

	int nbRegleAngle   = Evaluation(  -30, regleAngle);
	int nbRegleVitesse = Evaluation(  40, regleVitesse);

	for(int i = 0; i != nbRegleAngle;i++){	
		printf("Modalité Angle %d : %s %f\n", i, regleAngle[i].nom, regleAngle[i].etat);


	}

	for(int i = 0; i != nbRegleVitesse;i++){	
		printf("Modalité Vitesse %d : %s %f \n", i, regleVitesse[i].nom ,  regleVitesse[i].etat );

	}
	//returnvitesseEval(20);Il nous connais déja -> et en plus j'ai l'impreton il sen bas t le socuilles
	for(int i = 0; i != nbRegleAngle;i++){
		for(int j = 0; j != nbRegleVitesse;j++){

			int x = getIndexFromName(regleAngle[i].nom);
			int y = getIndexFromName(regleVitesse[j].nom);

			if (x == -1 || y == -1) continue;
			if( strcmp(tabRules[x][y].nom , "ZZ") == 0) continue;

			
			regleResultat[nbRegleResultat] = tabRules[x][y];
			regleResultat[nbRegleResultat].modalite1 =  getModalite(regleAngle[i]);
			regleResultat[nbRegleResultat].modalite2 =  getModalite(regleVitesse[j]);
			nbRegleResultat++;

		}
	}


	
	printf("\n\n");
	int intervalmax  = -1000;
	int intervalMin  = 10000;

	for(int i = 0; i != nbRegleResultat;i++){	

		printf("Regle %d : %s \n", i, regleResultat[i].nom);
		printf("Modalité 1 :  %s : %f \n", regleResultat[i].modalite1.nom , regleResultat[i].modalite1.etat); 
		printf("Modalité 2 :  %s : %f \n", regleResultat[i].modalite2.nom , regleResultat[i].modalite2.etat);

		if( regleResultat[i].modalite1.etat < regleResultat[i].modalite2.etat){
				if(  regleResultat[i].modalite1.max > intervalmax )
					intervalmax = regleResultat[i].modalite1.max;

				if(  regleResultat[i].modalite1.min < intervalMin )
					intervalMin = regleResultat[i].modalite1.min;


		}
		else {

				if(  regleResultat[i].modalite2.max > intervalmax )
					intervalmax = regleResultat[i].modalite2.max;

				if(  regleResultat[i].modalite2.min < intervalMin )
					intervalMin = regleResultat[i].modalite2.min;

				// on travaille sur la modalite 1
				regleResultat[i].modalite1 = regleResultat[i].modalite2;
		
		}
	}
	
float value = 0.0;
float up= 0.0;
float down = 0.0;

		printf("NOMBRE DE REGLE ACTIVER :  %d\n", nbRegleResultat);

	for(int IndexRegle = 0; IndexRegle != nbRegleResultat;IndexRegle++){	

		printf("Regle %d :  min : %f\n", IndexRegle , regleResultat[IndexRegle].modalite1.etat);
				printf("Regle %d :  nom : %s\n", IndexRegle , regleResultat[IndexRegle].modalite1.nom);



	}
float valTest;
	int valMAX = regleResultat[0].modalite1.etat > regleResultat[1].modalite1.etat ? regleResultat[0].modalite1.etat : regleResultat[1].modalite1.etat;
	for ( int i = intervalMin ; i <  intervalmax ; i++){
		value = -1;

		for(int IndexRegle = 0; IndexRegle != nbRegleResultat;IndexRegle++){	

			if( valbetween(regleResultat[IndexRegle].modalite1.min  , regleResultat[IndexRegle].modalite1.max , i )){
				
				valTest =  fctAppartenance(i,regleResultat[IndexRegle].modalite1.nom);	
				if( valTest > regleResultat[IndexRegle].modalite1.etat)
					valTest = regleResultat[IndexRegle].modalite1.etat;

			}
			else {

				valTest =  fctAppartenance(i,regleResultat[IndexRegle].modalite1.nom);
				if( valTest > regleResultat[IndexRegle].modalite1.etat)
					valTest = regleResultat[IndexRegle].modalite1.etat;


			}
				if( valTest > value)
					value = valTest;
		}



		printf (" intrval %d  value %f\n", i, value);
		up = (float) ( (float)i*value ) + up;
		down += value; 
	//		printf (" up %f  down %f\n", up, down);

	}

	float resultat = up/down;
	//int intervalMax = getIntervalMin(regleResultat);
	printf("Intervalle Min :  %d - Intervalle max = %d \n", intervalMin , intervalmax);
	printf("resultat %f \n", resultat);



	printf("\n--------------------------------------\n");
	return 0;
}