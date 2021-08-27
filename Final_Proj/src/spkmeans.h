#pragma once

#include "kmeans.h"

/* Structures Declarations */
typedef struct Graph {
    double **vertices;
    double **weights;
    double **lnorm;
    double *degrees;
    int N, dim;
} Graph;

typedef enum goal { spk = (int)'s', 
                    wam = (int)'w',
                    ddg = (int)'d', 
                    lnorm = (int)'l', 
                    jacobi = (int)'j' } goal;

/* Functions Declarations */
void compute_wam(Graph *graph);
void compute_ddg(Graph *graph);
void compute_lnorm(Graph *graph);
void compute_jacobi(double **A, int N, double **eign_vecs, double *eign_vals);
double compute_distance(double *vec1, double *vec2, int dim);
double compute_degree(double **weights, int v_idx, int n);
void sort_by_eigen_values(double **vectors, double *values, int n);
void read_data(Graph *graph, char *file_path);
int get_heuristic(double *eigenvalues, int N);
void form_U(double **U, double **eigenvectors, double *eigenvalues, double *eigenvalues_sorted, int N, int K);
void form_T(double **U, int N, int K);
double **init_spk_datapoints(Graph *graph, int *K);
void compute_by_goal(Graph *graph, goal goal);
double compute_distance_spk(double *vec1, double *vec2, int dim);

/* Matrix Utils */
void print_matrix(double **mat, int rows, int cols);
void print_transpose_matrix(double **mat, int rows, int cols);
void print_vector_as_matrix(double *diag, int n);
void multi_vec_mat(double *vec, double **mat, int n, double **res);
void multi_mat_vec(double **mat, double *vec, int n, double **res);
void inverse_sqrt_vec(double *vector, int N, double *inv_sqrt_vec);

/* Memory Utils */
double *calloc_1d_array(int size);
double **calloc_2d_array(int rows, int cols);
void free_2d_array(double **array);
void free_graph(Graph *graph, goal goal);

/* General Utils */
int get_sign(double d);
int cmp_func (const void *a, const void *b);
void my_assert(int status);
