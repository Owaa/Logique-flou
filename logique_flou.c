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

/* Prend en paramettre le nom de la fonction de la fonction d'appartenance pour calculer la valeur*/

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

	//Initialise le nombre de d'ensemble activer
	int nbRegle = 0;
	
	//Si la vaeur est compris dans un ensemble
	if( valbetween( -90 , -45 , angle) == 1){
			//on set les valeur de l'ensemble
			regle[nbRegle].nom   = "NM";
		 	regle[nbRegle].angle = angle;	
		 	regle[nbRegle].min = -90;
			regle[nbRegle].max = -45;
			//L'etat corespond au degré d'appartennance
			regle[nbRegle].etat  = max(min(1,(-45-angle)/45),0);	
			//Incremente le nombre d'enssemble activer
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

	
}





int main(int argc , char *argv[]){
	

	printf("\n--------------------------------------\n");
	printf("\n");


	if( argc < 2){

				printf("\nLe programme prend en paramettre un angle et une vitesse\n");
				printf("\n\n--------------------------------------------\n");

				exit(EXIT_FAILURE);
	}
	//	Récupération des Input
	int AngleInput = atoi(argv[1]);
	int VitesseInput = atoi(argv[2]);

	//Déclaration desvariables
	regle_t regleResultat[4];//Tableaux des régles activer
	regle_t tabRules[5][5];//Tableaux de l'ensemble des regles
	regle_t regleAngle[2];//Tableaux des modalité activer par l'input Angle
	regle_t regleVitesse[2];//Tableaux des modalité activer par l'input Vitesse
	int nbRegleResultat = 0;

	//Initialise le tableaux des régles
	for(int i = 0; i != 5;i++)
		for(int j = 0; j != 5; j++)
			CreatReagle ( "ZZ" , 0, 0 , 0, 0, &tabRules[i][j], 0 , 0);//On met des 'Fausses' regles partout

	

	//Ensuite On creer les vrais regles
	CreatReagle ( "NM" , 0, 0 , 0, 0, &tabRules[0][2] , -45 , -90);
	CreatReagle ( "NS" , 0, 0 , 0, 0, &tabRules[1][1] , 0 , -90);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[1][3] , 45 , -45);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[2][2] , 45 , -45);
	CreatReagle ( "ZR" , 0, 0 , 0, 0, &tabRules[3][1] , 45 , -45);
	CreatReagle ( "PS" , 0, 0 , 0, 0, &tabRules[3][3] , 90 , 0);
	CreatReagle ( "PM" , 0, 0 , 0, 0, &tabRules[4][2] , 90 , 45);

	
	// On evalue qu'elle modaité est activer 
	int nbRegleAngle   = Evaluation(  AngleInput , regleAngle);
	int nbRegleVitesse = Evaluation(  VitesseInput , regleVitesse);


	//	On Print les modalité activer et leur degre d'appartennace
	for(int i = 0; i != nbRegleAngle;i++)
		printf("Modalité Angle %d : %s %f\n", i, regleAngle[i].nom, regleAngle[i].etat);
	for(int i = 0; i != nbRegleVitesse;i++)
		printf("Modalité Vitesse %d : %s %f \n", i, regleVitesse[i].nom ,  regleVitesse[i].etat );



	// On calcul quelle regle sera activer 
	for(int i = 0; i != nbRegleAngle;i++){//Pour chaque modalité angle
		for(int j = 0; j != nbRegleVitesse;j++){//Pour chaque modalité vitesse

			//	Get l'index de la regle si elle est activer
			int x = getIndexFromName(regleAngle[i].nom);
			int y = getIndexFromName(regleVitesse[j].nom);


			if (x == -1 || y == -1) continue; // si lindex n'a pas été trouver on passe
			if( strcmp(tabRules[x][y].nom , "ZZ") == 0) continue;//Si on a activer une 'fausses' regles on passe

			//On set le tableaux des regles activer
			regleResultat[nbRegleResultat] = tabRules[x][y];
			// On set les modalite qui on activer la regles
			regleResultat[nbRegleResultat].modalite1 =  getModalite(regleAngle[i]);
			regleResultat[nbRegleResultat].modalite2 =  getModalite(regleVitesse[j]);
			//	Increlentre le nombre de regles
			nbRegleResultat++;


		}
	}


	
	printf("\n\n");

	//	Calcul des intervales min et max
	int intervalmax  = -1000;
	int intervalMin  = 10000;

	for(int i = 0; i != nbRegleResultat;i++){//	Pour chaque regles activer

		//On l'a print
		printf("Regle %d : %s \n", i, regleResultat[i].nom);
		printf("Modalité 1 :  %s : %f \n", regleResultat[i].modalite1.nom , regleResultat[i].modalite1.etat); 
		printf("Modalité 2 :  %s : %f \n", regleResultat[i].modalite2.nom , regleResultat[i].modalite2.etat);


		//Permet de faire le min entre les deux modalité
		// et de recupere les intervalles
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
	

	//	print le nombre de regles et les modalité min de chaque regles
	printf("NOMBRE DE REGLE ACTIVER :  %d\n", nbRegleResultat);
	for(int IndexRegle = 0; IndexRegle != nbRegleResultat;IndexRegle++)
		printf("Regle %d Modalité\tMin : %f\tNom : %s\n", IndexRegle , regleResultat[IndexRegle].modalite1.etat , regleResultat[IndexRegle].modalite1.nom);



	// Calcul du centre de graité de l'enssemble flou
	// Il faudra faire le Max en entres les deux modalité
	float valTest;
	float value = 0.0;
	float up= 0.0;
	float down = 0.0;

	//On incremente la valeur a calculer sur l'ensselble precedement définit
	for ( int i = intervalMin ; i <  intervalmax ; i++){
		value = -1;

		for(int IndexRegle = 0; IndexRegle != nbRegleResultat;IndexRegle++){		//Pour ltoutes les regles activer


			//	Calcule de la fct d'appartenance
			valTest =  fctAppartenance(i,regleResultat[IndexRegle].modalite1.nom);	
			//	On fait attention a ne pas depacer la val max de modalité
			if( valTest > regleResultat[IndexRegle].modalite1.etat)
				valTest = regleResultat[IndexRegle].modalite1.etat;

			//	On prend le max entres les deux modalité
			if( valTest > value)
				value = valTest;
		}


		//	Décommenter pour afficher touts les calcules
		//printf ("Intrval : %d\tValeur : %f\n", i, value);

		//Calcule d'un element du centre de garvité
		up = (float) ( (float)i*value ) + up;
		down += value; 

	}

	//	Fait la moyenne de tout les élement
	float resultat = up/down;
	//Print le résultat
	printf("Intervalle Min :  %d - Intervalle max = %d \n", intervalMin , intervalmax);
	printf("resultat %f \n", resultat);



	printf("\n--------------------------------------\n");
	return 0;
}