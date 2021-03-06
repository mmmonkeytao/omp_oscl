#ifndef LPOSC_H
#define LPOSC_H

#include "OnlineStarClustering.h"
#include "Vertex.h"

#include <iostream>
#include <vector>
#include <map>
#include <Eigen/Dense>

using namespace std;

namespace oscl{

  
  class LPOSC: public OnlineStarClustering{
    
  public:

    
    LPOSC(uint feaSize, string feaType, double sigma = 0.6);
    ~LPOSC(){};

    void center_label_propagation(const char* type);

    void initialize_Ainv();
    void initialize_current_label_vector(int);
    void insert(Eigen::VectorXd vec, int label);
    void jacobi_label_propagation();

    void init_center_star_list();
    void update_edge_graph();

    void save_eval_files(const char* prefix);
    void current_accuracy();
    void calc_Vmeasure();
    
  private:

    // store all previous propagated labels
    vector<Eigen::VectorXi> totlabels_threshold;
    vector<Eigen::VectorXi> totlabels_edges;
    vector<Eigen::VectorXi> totlabels_alledges;
    
    Eigen::MatrixXd current_threshold_graph;
    Eigen::MatrixXd totedges_graph;
    Eigen::MatrixXd current_edges_graph;
    
    vector<vector<uint> > allcenterslist;
    vector<vector<uint> > allstarslist;

    vector<double> homo, complete;
    
    Eigen::VectorXd Y0;
    Eigen::MatrixXd Ainv;
    Eigen::VectorXi Ylabel;
    
    map<int, uint> labelist;

    const double alpha = 0.5;
    const double u = alpha/(1-alpha);
    const double eps = 10e-2;
    
  };

}

#endif
