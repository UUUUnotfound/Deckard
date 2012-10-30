
#include <graph.h>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

/********************
 * class Graph
 *
 * *****************/
Graph::Graph():
      attributeIDs(), graphName("no name"), graph_functionSig("no signature"),
      graphNodes(), attributes(), graphEntry(NULL) {
}

Graph::~Graph() {
}

int Graph::nodeCount()
{
   return graphNodes.size();
}

int Graph::edgeCount()
{
   int c = 0;
   for(map<string, GraphNode*>::const_iterator it = graphNodes.begin();
         it!=graphNodes.end(); ++it) {
      c += it->second->children.size();
   }
   return c;
}

bool Graph::hasNode(string n)
{
   map<string, GraphNode*>::const_iterator it = graphNodes.find(n);
   if ( it==graphNodes.end() )
      return false;
   else
      return true;
}

bool Graph::hasNode(GraphNode* n)
{
   if ( n==NULL )
      return false;
   return hasNode(n->nodeName);
}

GraphNode* Graph::getNode(string n)
{
   map<string, GraphNode*>::const_iterator it = graphNodes.find(n);
   if ( it==graphNodes.end() )
      return NULL;
   else
      return it->second;
}

bool Graph::addNode(GraphNode* n) {
   assert(n!=NULL);
   if ( hasNode(n) )
      return false;
   graphNodes.insert(make_pair(n->nodeName, n));
   return true;
}

bool Graph::addNode(string n) {
   if ( hasNode(n) )
      return false;
   graphNodes.insert(make_pair(n, new GraphNode(n)));
   return true;
}

bool Graph::addEdge(GraphNode* lhs, GraphNode* rhs) {
   assert(lhs!=NULL && rhs!=NULL);
   bool flag = GraphNode::addEdge(lhs, rhs);
   bool b1 = addNode(lhs);
   bool b2 = addNode(rhs);
   return flag || b1 || b2;
}

GraphNode* Graph::updateEntries()
{
   int count = 0;
   for(map<string, GraphNode*>::const_iterator nitr = graphNodes.begin();
         nitr!=graphNodes.end(); ++nitr) {
      if ( nitr->second->parents.size()<=0 ) {
         count++;
         if ( count==1 ) {
            if ( graphEntry!=nitr->second ) {
               graphEntry = nitr->second;
            }
         }
      }
   }
   if ( count>1 ) {
      cerr << "Warning: " << count << " graph entires found in Graph::updateEntries(). Only support one for AST now." << endl;
   }
   return graphEntry;
}

string Graph::getGraphName()
{
	return graphName;
}

bool Graph::setGraphName(string n) {
   graphName = n;
   return true;
}

int Graph::getAttributeID(string n) {
   return attributeIDs.getNameId(n);
}

int Graph::getOrAddAttributeID(string n)
{
   return attributeIDs.getOrAddNameId(n);
}

string Graph::getGraphAttribute(string n) {
   int id = getAttributeID(n);
   if ( attributeIDs.isIDValid(id) ) {
      map<int, string>::const_iterator attr = attributes.find(id);
      if ( attr!=attributes.end() )
         return attr->second;
   }
   return NameMap::invalidName;
}

string Graph::getNodeAttribute(string name, GraphNode* node) {
   int id = getAttributeID(name);
   return node->getAttribute(id);
}

bool Graph::addGraphAttribute(string name, string value) {
   int id = getOrAddAttributeID(name);
   map<int, string>::const_iterator attr = attributes.find(id);
   if ( attr!=attributes.end() )
      return false;
   attributes[id] = value;
   return true;
}

bool Graph::addNodeAttribute(string name, string attr, GraphNode* node) {
   int id = getOrAddAttributeID(name);
   return node->addAttribute(id, attr);
}

int Graph::printNodes(ostream & out)
{
   for(map<string, GraphNode*>::const_iterator it = graphNodes.begin();
         it!=graphNodes.end(); ++it) {
      out << "NODE: " << it->second->nodeName;
      printNodeAttributesOnly(it->second, out);
      out << endl;
   }
   return graphNodes.size();
}

int Graph::printNodeAttributesOnly(GraphNode* n, ostream & out)
{
   assert(n!=NULL);
   if ( n->attributes.size()<1 )
      return 0;
   out << " [ ";
   for(map<int, string>::const_iterator it = n->attributes.begin();
         it!=n->attributes.end(); ++it) {
      out << attributeIDs.getIDName(it->first);
      out << "=" << it->second << " ";
   }
   out << " ] ";
   return n->attributes.size();
}

int Graph::printEdges(ostream & out)
{
   int c = 0;
   for(map<string, GraphNode*>::const_iterator it = graphNodes.begin();
         it!=graphNodes.end(); ++it) {
      for(vector<GraphNode*>::const_iterator e = it->second->children.begin();
            e!=it->second->children.end(); ++e) {
         out << "EDGE: " << it->second->nodeName << " -> " << (*e)->nodeName << endl;
      }
      c += it->second->children.size();
   }
   return c;
}

int Graph::printGraph(ostream & out)
{
   out << "GRAPH: " << graphName << endl;
   printAttributesWithNames(&attributes, "   ", out);
   int c = printNodes(out);
   c += printEdges(out);
   return c;
}

bool Graph::mergeGraphAttributes(map<int, string>* attrs) {
   assert(attrs!=NULL);
   attributes.insert(attrs->begin(), attrs->end());
   return true;
}

bool Graph::mergeNodeAttributes(map<int, string>* attrs, GraphNode* node) {
   return node->mergeAttributes(attrs);
}

std::map<int, std::string>* Graph::getAttributes()
{
   return &attributes;
}

int Graph::printAttributesWithNames(const map<int, string>* attrs, std::string prefix, ostream & out)
{
   for(map<int, string>::const_iterator it = attrs->begin();
         it != attrs->end(); ++it) {
      out << prefix << attributeIDs.getIDName(it->first) << "=" << it->second << endl;
   }
   return attrs->size();
}

int Graph::printAttributesWithIDs(const map<int, string>* attrs, std::string prefix, ostream & out)
{
   for(map<int, string>::const_iterator it = attrs->begin();
         it != attrs->end(); ++it) {
      out << prefix << it->first << "=" << it->second << endl;
   }
   return attrs->size();
}

bool Graph::dumpGraph(const char * ofname, bool toOverride)
{
   ifstream inp;
   ofstream out;
   string outputfn = (ofname==NULL ? graph_functionSig : ofname) + ".grp.dot";

   // prepare the output file:
   if(!toOverride) {
      inp.open(outputfn.c_str(), ifstream::in);
      inp.close();
      if(!inp.fail()) {
         cerr << "Warning: graph dump file exists already: " << outputfn << " ...skip" << endl;
         return false;
      }
      inp.clear(ios::failbit);
   }
   out.open(outputfn.c_str(), ofstream::out);
   if(out.fail()) {
      cerr << "Error: cannot open graph dump file: " << outputfn << endl;
      return false;
   }

   // print the graph to the file:
   cerr << "# Dumping the graph into file: " << outputfn << endl;
   out << "# " << graph_functionSig << endl;
   printGraph(out);

   // close the file:
   out.close();
   return true;
}

vector<GraphNode*> Graph::reorderNodes(string attr)
{
   int id = getAttributeID(attr);
   vector<GraphNode*> nodes;
   for(map<string, GraphNode*>::const_iterator nitr = graphNodes.begin();
         nitr!=graphNodes.end(); ++nitr) {
      nodes.push_back(nitr->second);
   }
   CompareGraphNode comp(id);
   sort(nodes.begin(), nodes.end(), comp);
   return nodes;
}

Graph* Graph::combine(Graph* lhs, Graph* rhs)
{
   Graph* rsl = new Graph();
   if ( lhs->graphName!=rhs->graphName ) {
      cerr << "Warning: different graph? Really can intersect? Continue anyway..." << endl;
      rsl->setGraphName(lhs->graphName);
   }
   if ( lhs->graph_functionSig!=rhs->graph_functionSig ) {
      cerr << "Warning: different function signature? Really can intersect? Continue anyway..." << endl;
      rsl->graph_functionSig = lhs->graph_functionSig;
   }
   // combine graphNodes
   rsl->graphNodes = lhs->graphNodes;
   for(map<string, GraphNode*>::const_iterator ritr = rhs->graphNodes.begin();
         ritr!=rhs->graphNodes.end(); ++ritr) {
      GraphNode* n = rsl->getNode(ritr->first);
      if ( n!=NULL ) {
         if ( n!=ritr->second ) {
            cerr << "Warning: different graph node instances for the same name when combing? Continue anyway..." << endl;
         }
      } else {
         rsl->graphNodes.insert(*ritr);
      }
   }
   // combine attributeIDs
   rsl->attributeIDs = NameMap::combineNameMap(lhs->attributeIDs, rhs->attributeIDs);
   // combine attributes
   rsl->attributes = lhs->attributes;
   for(map<int, string>::const_iterator ritr = rhs->attributes.begin();
         ritr!=rhs->attributes.end(); ++ritr) {
      map<int, string>::const_iterator aitr = lhs->attributes.find(ritr->first);
      if ( aitr!=lhs->attributes.end() ) {
         if ( aitr->second!=ritr->second ) {
            cerr << "Warning: different attribute values when combing attribute ID-" << aitr->first << "? Continue anyway..." << endl;
         }
      } else {
         rsl->attributes.insert(*ritr);
      }
   }
   
   return rsl;
}

Graph* Graph::intersect(Graph* lhs, Graph* rhs)
{
   Graph* rsl = new Graph();
   if ( lhs->graphName!=rhs->graphName ) {
      cerr << "Warning: different graph? Really can intersect? Continue anyway..." << endl;
      rsl->setGraphName(lhs->graphName);
   }
   if ( lhs->graph_functionSig!=rhs->graph_functionSig ) {
      cerr << "Warning: different function signature? Really can intersect? Continue anyway..." << endl;
      rsl->graph_functionSig = lhs->graph_functionSig;
   }
   // intersect graphNodes
   for(map<string, GraphNode*>::const_iterator litr = lhs->graphNodes.begin();
         litr!=lhs->graphNodes.end(); ++litr) {
      map<string, GraphNode*>::const_iterator ritr = rhs->graphNodes.find(litr->first);
      if ( ritr==rhs->graphNodes.end() )
         continue;
      if ( litr->second!=ritr->second ) {
         cerr << "Warning: different graph node instances for the same name when intersecting? Continue anyway..." << endl;
      }
      rsl->graphNodes.insert(*litr);
   }
   // combine attributeIDs
   rsl->attributeIDs = NameMap::combineNameMap(lhs->attributeIDs, rhs->attributeIDs);
   // intersect attributes
   for(map<int, string>::const_iterator litr = lhs->attributes.begin();
         litr!=lhs->attributes.end(); ++litr) {
      map<int, string>::const_iterator ritr = rhs->attributes.find(litr->first);
      if ( ritr==rhs->attributes.end() )
         continue;
      if ( litr->second!=ritr->second ) {
         cerr << "Warning: different attribute values for attribute ID-" << litr->first << "? Really can intersect? Continue anyway..." << endl;
      }
      rsl->attributes.insert(*litr);
   }
   
   return rsl;
}

/********************************
 * class GraphNode
 * ************************/
GraphNode::GraphNode():children(), parents(), attributes(), nodeName("no name node")
{
}

GraphNode::GraphNode(string n):children(), parents(), attributes(), nodeName(n)
{
}

GraphNode::~GraphNode()
{
}

string GraphNode::getAttribute(int id) const
{
   map<int, string>::const_iterator attr = attributes.find(id);
   if ( attr!=attributes.end() )
      return attr->second;
   return NameMap::invalidName;
}

bool GraphNode::addAttribute(int id, string n)
{
   map<int, string>::const_iterator attr = attributes.find(id);
   if ( attr!=attributes.end() )
      return false;
   attributes[id] = n;
   return true;
}

bool GraphNode::mergeAttributes(map<int, string>* attrs)
{
   assert(attrs!=NULL);
   attributes.insert(attrs->begin(), attrs->end());
   return true;
}

bool GraphNode::hasEdge(GraphNode* n)
{
   if ( n==NULL )
      return false;
   for(vector<GraphNode*>::const_iterator it = children.begin();
         it!=children.end(); ++it) {
      // pointer equivalence is ok, assuming node names are unique
      if ( *it==n )
         return true;
   }
   for(vector<GraphNode*>::const_iterator it = parents.begin();
         it!=parents.end(); ++it) {
      if ( *it==n )
         return true;
   }
   return false;
}

bool GraphNode::isChildOf(GraphNode* n)
{
   if ( n==NULL )
      return false;
   for(vector<GraphNode*>::const_iterator it = parents.begin();
         it!=parents.end(); ++it) {
      if ( *it==n )
         return true;
   }
   return false;
}

bool GraphNode::isParentOf(GraphNode* n)
{
   if ( n==NULL )
      return false;
   for(vector<GraphNode*>::const_iterator it = children.begin();
         it!=children.end(); ++it) {
      if ( *it==n )
         return true;
   }
}

bool GraphNode::addChild(GraphNode* n)
{
   assert(n!=NULL);
   if ( isParentOf(n) )
      return false;
   children.push_back(n);
   return true;
}

bool GraphNode::addParent(GraphNode* n)
{
   assert(n!=NULL);
   if ( isChildOf(n) )
      return false;
   parents.push_back(n);
   return true;
}

bool GraphNode::addEdge(GraphNode* lhs, GraphNode* rhs)
{
   assert(lhs!=NULL && rhs!=NULL);
   bool flag = lhs->addChild(rhs);
   bool b = rhs->addParent(lhs);
   return flag || b;
}

int GraphNode::printParents(string prefix, ostream & out)
{
   for(vector<GraphNode*>::const_iterator it = parents.begin();
         it!=parents.end(); ++it) {
      out << prefix << (*it)->nodeName << endl;
   }
   return parents.size();
}

int GraphNode::printChildren(string prefix, ostream & out)
{
   for(vector<GraphNode*>::const_iterator it = children.begin();
         it!=children.end(); ++it) {
      out << prefix << (*it)->nodeName << endl;
   }
   return children.size();
}

int GraphNode::printNode(ostream & out)
{
   int c = 1;
   out << "NODE: " << nodeName << endl;
   c += printParents("<-", out);
   c += printChildren("->", out);
   return c;
}

int GraphNode::printNodeAttributesOnly(ostream & out)
{
   if ( attributes.size()<1 )
      return 0;
   out << " [ ";
   for(map<int, string>::const_iterator it = attributes.begin();
         it!=attributes.end(); ++it) {
      out << it->first << "=" << it->second << " ";
   }
   out << " ] ";
   return attributes.size();
}

/*********************************
 * CompareGraphNode
 */
CompareGraphNode::CompareGraphNode(int attrID)
{
   compareFieldID = attrID;
}

bool CompareGraphNode::operator()(const GraphNode* lhs, const GraphNode* rhs)
{
   if(lhs==NULL) return true;
   if(rhs==NULL) return false;
   string lstr = lhs->getAttribute(compareFieldID);
   if ( lstr==NameMap::invalidName )
      return true;
   string rstr = rhs->getAttribute(compareFieldID);
   if ( rstr==NameMap::invalidName )
      return false;

   stringstream lss(lstr);
   stringstream rss(rstr);
   int lnum, rnum;
   if ( !(lss >> lnum) || !(rss >> rnum) ) {
      return lstr < rstr;
   } else {
      return lnum < rnum;
   }
}

