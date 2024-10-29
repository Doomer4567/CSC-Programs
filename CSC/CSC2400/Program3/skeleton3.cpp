//Author: Ethan Byker
//Class: CSC2400
//Description: Alogrithm to solve the Traveling Salesman Promblem


#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstddef>
#include <cstring>
#include <tuple>

typedef std::size_t vertex_t;
typedef std::tuple<vertex_t,vertex_t,double> weighted_edge_t;

/* Get the source of a weighted edge.
 *
 * This function returns the source of a weighted edge.
 *
 * @param edge - the edge
 *
 * @return std::get<0>(edg)
 * */
vertex_t get_source(const weighted_edge_t &edg);

/* Get the destination of a weighted edge.
 *
 * This function returns the destination of a weighted edge.
 *
 * @param edge - the edge
 *
 * @return std::get<1>(edg)
 * */
vertex_t get_destination(const weighted_edge_t &edg);

/* Get the weight of a weighted edge.
 *
 * This function returns the weight of a weighted edge.
 *
 * @param edge - the edge
 *
 * @return std::get<2>(edg)
 * */
vertex_t get_weight(const weighted_edge_t &edg);

/* Determine the number of vertices in the graph.
 *
 * This function determines the number of vertices in the graph represented
 * by a vector of weighted edges. It is assumed that the number of vertices
 * is given by the largest source or destination vertex in the list of edges
 * plus one.
 *
 * @param edges - a vector of weighted edges defining a graph
 *
 * @return the number of vertices in the graph represented by edges
 * */
unsigned int get_vertex_count(const std::vector<weighted_edge_t> &edges);

/* Reads weighted edges from a file.
 *
 * This function reads weighted edges from filename and returns them as a
 * std::vector<weighted_edge_t>. each line of the file is assumed to be of the
 * form "src dst wt" where src is the source vertex, and dst is the destination
 * vertex, and wt is the weight of the edge. All vertices are assumed to be
 * unsigned integers that can be stored as a std::size_t (i.e., in a vertex_t).
 * Duplicate edges found in the file are ignored.
 *
 * @param filename - name of the file to read
 *
 * @return a vector of edges read from filename
 *
 * @throws std::runtime_error - thrown if there is an error reading the file
 * */
std::vector<weighted_edge_t> read_graph(const std::string &filename);

/* Solves the traveling salesman problem by brute force.
 *
 * This function solves the TSP via brute force. It accepts a vector of
 * weighted edges and count of the number of vertices. These two values
 * together define a weighted graph. 
 *
 * @param edges - a vector of weighted edges in the graph
 *
 * @param n_vertices - the number of vertices in the graph;
 *                     the vertices are 0 ... n_vertices-1
 *
 * @return the cost of the minimum Hamiltonian cycle or infinity if none exists
 * */
double TSP(const std::vector<weighted_edge_t> &edges, unsigned int n_vertices);






double TSP(const std::vector<weighted_edge_t> &edges, unsigned int n_vertices) {
	/* IMPLEMENT THIS FUNCTION */
	std::vector<std::vector<vertex_t> > adj_matrix;

	std::vector<vertex_t> vec_node;

	for(int i = 0; i < edges.size(); i++){
		//grabs the src,dst,wt from edges and pushes it into a vector
		vec_node.push_back(get_source(edges[i]));
		vec_node.push_back(get_destination(edges[i]));
		vec_node.push_back(get_weight(edges[i]));
		//it then pushes that data into a matrix
		adj_matrix.push_back(vec_node);
		//quick while command to empty out the vector for the next set of data
		while(vec_node.empty()) { vec_node.pop_back(); }
	}
	
	vertex_t Home_Node = adj_matrix[0][0];
	double min_cost = 0;
	double wt = adj_matrix[0][3];
	for(int i = 1; i < adj_matrix.max_size(); i++){
		if(adj_matrix[i][0] == adj_matrix[i-1][0] && adj_matrix[i][3] < wt){
			wt = adj_matrix[i][3];
		} else if (adj_matrix[i][0] != adj_matrix[i-1][0]) {
			min_cost += wt;
			wt = adj_matrix[i][3];
		}
		if(adj_matrix[i][0] == Home_Node && adj_matrix[0][1] == Home_Node){
			break;
		} else if (adj_matrix[i][1] == Home_Node) {
			return min_cost;
		}
	}


	min_cost = std::numeric_limits<double>::infinity();
	return min_cost;
}

vertex_t get_source(const weighted_edge_t &edg) {
	return std::get<0>(edg);
}

vertex_t get_destination(const weighted_edge_t &edg) {
	return std::get<1>(edg);
}

vertex_t get_weight(const weighted_edge_t &edg) {
	return std::get<2>(edg);
}

unsigned int get_vertex_count(const std::vector<weighted_edge_t> &edges) {
	unsigned int n_vertices = 0;
	if(!edges.empty()) {
		std::set<vertex_t> vertex_set;
		
		/* add the source vertices to vertex_set */
		std::transform(
			edges.begin(),
			edges.end(),
			std::inserter(vertex_set, vertex_set.end()),
			get_source
		);
		
		/* add the destination vertices to vertex_set */
		std::transform(
			edges.begin(),
			edges.end(),
			std::inserter(vertex_set, vertex_set.end()),
			get_destination
		);

		/* get the largest vertex from vertex_set and add 1 */
		n_vertices = *std::max_element(vertex_set.begin(), vertex_set.end()) + 1;
	}
	
	return n_vertices;
}

std::vector<weighted_edge_t> read_graph(const std::string &filename) {
	std::vector<weighted_edge_t> edges;
	std::ifstream file(filename);
	if(file) {
		/* read edges into a set to remove duplicates */
		std::set<weighted_edge_t> edge_set;

		vertex_t src, dst;
		double wt;
		while(file >> src && file >> dst && file >> wt) {
			edge_set.insert( weighted_edge_t(src,dst,wt) );
		}

		/* check if there was an error reading in the file */
		if(file.bad()) { // i/o error
			std::ostringstream oss;
			oss << filename << ": " << strerror(errno);
			throw std::runtime_error(oss.str());
		}
		else if((file.fail() && !file.eof())) { // conversion error
			std::ostringstream oss;
			oss << filename << ": error reading file";
			throw std::runtime_error(oss.str());
		}

		/* copy the edges read to the edges vector */
		std::copy(edge_set.begin(), edge_set.end(), std::back_inserter(edges));
	}
	else { // error opening file
		std::ostringstream oss;
		oss << filename << ": " << strerror(errno);
		throw std::runtime_error(oss.str());
	}

	if(edges.empty()) {
		std::ostringstream oss;
		oss << filename << ": file does not contain any edges";
		throw std::runtime_error(oss.str());

	}
	return edges;
}

void usage(int argc, char *argv[]) {
	if(argc != 2) {
		std::cerr << "Invalid number of command line arguments." << std::endl << std::endl;
	}
	std::cout << "usage: ";
	std::cout << argv[0] << " infile" << std::endl;
	std::cout << "  infile - file containing a list of edges" << std::endl << std::endl;
	std::cout << "It is assumed that each line of <infile> contains an edge of the" <<std::endl;
	std::cout << "form <src> <dst> <wt>." << std::endl;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		usage(argc, argv);
	}
	else {
		try {
			std::vector<weighted_edge_t> edges = read_graph(argv[1]);
			unsigned int n_vertices = get_vertex_count(edges);
			double min_cost = TSP(edges, n_vertices);
			if(min_cost == std::numeric_limits<double>::infinity()) {
				std::cout << "No Hamiltonian cycle exists." << std::endl;
			}
			else {
				std::cout << min_cost << std::endl;
			}
		}
		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

	return 0;
}
