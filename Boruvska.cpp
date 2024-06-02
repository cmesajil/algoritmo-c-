#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//arista
struct arista{
	int datoDestino;
	arista *sgteArista;
	int peso;
};
typedef arista *parista;


//vertice
struct vertice{
	int datoOrigen;
	arista *adyacente;
	vertice *sgteVertice;
};
typedef vertice *pvertice;

//grafo
class grafo{
	private:
		pvertice pGrafo;
	public:
		grafo();
		~grafo();
		void insertarVertice(int);
		void insertarArista(int,int,int);
		void imprimirGrafo();
		pvertice getpGrafo();
};

//Constructor

grafo::grafo(){
	pGrafo=NULL;
};
//destructor

pvertice grafo::getpGrafo(){
	pvertice p=pGrafo;
	return p;
}

grafo::~grafo(){
	pvertice p,rp;
	parista r,ra;
	p=pGrafo;
	while(p!=NULL){
		r=p->adyacente;
		while(r!=NULL){
			ra=r;
			r=r->sgteArista;
			delete ra;
		}
		rp=p;
		p=p->sgteVertice;
		delete rp;
	}
};
// insertar vertice 

void grafo::insertarVertice(int x){
	pvertice p;
	p=new vertice;
	p->datoOrigen=x;
	p->adyacente=NULL;
	p->sgteVertice=pGrafo;
	pGrafo=p;
};
	
//insertar Arista

void grafo::insertarArista(int x,int y,int pesito){
	pvertice p=pGrafo;
	parista a,b;
	if(p!=NULL){
		while(p!=NULL && p->datoOrigen!=x){
		p=p->sgteVertice;	
		}
		if(p!=NULL){
		    b=p->adyacente;
		    while(b!=NULL && b->datoDestino!=y){
		        b=b->sgteArista;
		    }
		    if(b==NULL){
			a=new arista;
			a->datoDestino=y;
			a->peso=pesito;
			a->sgteArista=p->adyacente;
			p->adyacente=a;
		    }
		}
	}
}
//imprimir

void grafo::imprimirGrafo(){
	pvertice p;
	parista a;
	p=pGrafo;
	if(p==NULL) {
		cout<<"Grafo vacio"<<endl;
	}
	else{
		while(p!=NULL){
			cout<<p->datoOrigen;
			a=p->adyacente;
			if(a!=NULL){
			while(a!=NULL){
				cout<<"->"<<a->datoDestino;
				a=a->sgteArista;
			}
			cout<<endl;
			}
			cout<<"|"<<endl;
			cout<<"v"<<endl;
			p=p->sgteVertice;
		}
	}
}



grafo findLowestArist(grafo g){
    pvertice p=g.getpGrafo();
    pvertice p1=g.getpGrafo();
    parista a,a1;
    grafo mst;
    int aux_menor=0;
    while(p1!=NULL){
        mst.insertarVertice(p1->datoOrigen);
        p1=p1->sgteVertice;
    }
    while(p!=NULL){
        
        a=p->adyacente;
        if(a!=NULL){
            aux_menor=a->peso;
            a1=a;
        while (a!=NULL){
            cout<<"pesos de "<<p->datoOrigen<<","<<a->datoDestino<<endl;
            cout<<a->peso<<endl;
             //lol
            if(a->peso<aux_menor){
                aux_menor=a->peso;
                a1=a; //
            }
            
            a=a->sgteArista;
        }
        cout<<"pesos ganador "<<aux_menor<<endl;
        mst.insertarArista(p->datoOrigen,a1->datoDestino,aux_menor);
        mst.insertarArista(a1->datoDestino,p->datoOrigen,aux_menor);
        }
        p=p->sgteVertice;
    }
    return mst;
}

vector<tuple<int,int,int>> Boruvska(grafo g){
    vector<tuple<int,int,int>> mst;
    pvertice p2=g.getpGrafo();
    pvertice p;
    int aux_menor=0;
    parista a,a1;
    vector<vector<int>> uncheckNodes;
    while(p2!=NULL){
        vector<int> a= {p2->datoOrigen};
        uncheckNodes.push_back(a);
        p2=p2->sgteVertice;
    }
    for(int i=0;i<uncheckNodes.size();i++){
        for(int j=0;j<uncheckNodes[i].size();j++){
            cout<<uncheckNodes[i][j]<<endl;
            p=g.getpGrafo();
            while(uncheckNodes[i][j]!=p->datoOrigen){
                p=p->sgteVertice;
            }
            
        
                a=p->adyacente;
                if(a!=NULL){
                    aux_menor=a->peso;
                    a1=a;
                    while (a!=NULL){
                        cout<<"pesos de "<<p->datoOrigen<<","<<a->datoDestino<<endl;
                        cout<<a->peso<<endl;
                        //lol
                        if(a->peso<aux_menor){
                            aux_menor=a->peso;
                            a1=a; //
                        }
            
                        a=a->sgteArista;
                    }
                    cout<<"pesos ganador "<<aux_menor<<endl;
                    mst.push_back(make_tuple(p->datoOrigen,a1->datoDestino,aux_menor));
                    mst.push_back(make_tuple(a1->datoDestino,p->datoOrigen,aux_menor));
                }
               
        }
    } 
    
     for (const auto& t : mst) {
        std::cout << "{" 
                  << std::get<0>(t) << ", "
                  << std::get<1>(t) << ", "
                  << std::get<2>(t) << "}\n";
    }
    return mst;
}    

void funcion(grafo g){
     vector<tuple<int,int,int>> mst;
    pvertice p2=g.getpGrafo();
    pvertice p;
    int aux_menor=0;
    parista a,a1;
    vector<vector<int>> uncheckNodes;
    bool verificar;
    
    while(p2!=NULL){
        vector<int> a= {p2->datoOrigen};
        uncheckNodes.push_back(a);
        p2=p2->sgteVertice;
    }
    
    while(uncheckNodes.size()!=1){
        
        
    
    for(int i=0;i<uncheckNodes.size();i++){
        for(int j=0;j<uncheckNodes[i].size();j++){
            cout<<uncheckNodes[i][j]<<endl;
            p=g.getpGrafo();
            //selec nodes
            while(uncheckNodes[i][j]!=p->datoOrigen){
                p=p->sgteVertice;
            }
            //-----------------------------
                a=p->adyacente;
                
                if(a!=NULL){
                    verificar=false;
                    //verificando si esta en el nodo
                    for(int k=0;k<uncheckNodes[i].size();k++){
                        if(a->datoDestino==uncheckNodes[i][k] && p->datoOrigen!=uncheckNodes[i][k]){
                            verificar=true;
                        }
                    }
                
                //-----------------------------
                    if(!verificar){
                    aux_menor=a->peso;
                    a1=a;
                    while (a!=NULL){
                        cout<<"pesos de "<<p->datoOrigen<<","<<a->datoDestino<<endl;
                        cout<<a->peso<<endl;
                        //lol
                        if(a->peso<aux_menor){
                            aux_menor=a->peso;
                            a1=a; //
                        }
            
                        a=a->sgteArista;
                    }
                    cout<<"pesos ganador "<<aux_menor<<endl;
                    mst.push_back(make_tuple(p->datoOrigen,a1->datoDestino,aux_menor));
                    mst.push_back(make_tuple(a1->datoDestino,p->datoOrigen,aux_menor));
                    }
                }
               
        }
    } 
    
    
    
    //update unchecktnodes
    
    
    
    
    }
    
     for (const auto& t : mst) {
        std::cout << "{" 
                  << std::get<0>(t) << ", "
                  << std::get<1>(t) << ", "
                  << std::get<2>(t) << "}\n";
    }
    //return mst;
}
int main(){
    
	grafo g;
	grafo mst;
	g.insertarVertice(7);
	g.insertarVertice(6);
	g.insertarVertice(5);
	g.insertarVertice(4);
	g.insertarVertice(3);
	g.insertarVertice(2);
	g.insertarVertice(1);
	g.insertarVertice(0);
	g.insertarArista(0,6,53);
	g.insertarArista(6,0,53);
	g.insertarArista(0,1,32);
	g.insertarArista(1,0,32);
	g.insertarArista(0,2,29);
	g.insertarArista(2,0,29);
	g.insertarArista(4,3,34);
	g.insertarArista(3,4,34);
	g.insertarArista(5,3,18);
	g.insertarArista(3,5,18);
	g.insertarArista(7,4,46);
	g.insertarArista(4,7,46);
	g.insertarArista(5,4,40);
	g.insertarArista(4,5,40);
	g.insertarArista(0,5,60);
	g.insertarArista(5,0,60);
	g.insertarArista(6,4,51);
	g.insertarArista(4,6,51);
	g.insertarArista(7,0,31);
	g.insertarArista(0,7,31);
	g.insertarArista(7,6,25);
	g.insertarArista(6,7,25);
	g.insertarArista(7,1,21);
	g.insertarArista(1,7,21);
	g.imprimirGrafo();
	cout<<"lowestArist---------------------------------------------------"<<endl;
	funcion(g);
	//findLowestArist(g).imprimirGrafo();
	
}
	

