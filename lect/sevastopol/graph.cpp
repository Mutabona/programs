  template <class G>
  struct IncidenceGraphConcept
  {
    typedef typename boost::graph_traits<G>::out_edge_iterator out_edge_iterator;
    void constraints() {
      function_requires< GraphConcept<G> >();
      function_requires< MultiPassInputIteratorConcept<out_edge_iterator> >();

      p = out_edges(u, g);
      e = *p.first;
      u = source(e, g);
      v = target(e, g);
    }
    void const_constraints(const G& g) {
      p = out_edges(u, g);
      e = *p.first;
      u = source(e, g);
      v = target(e, g);
    }
    std::pair<out_edge_iterator, out_edge_iterator> p;
    typename boost::graph_traits<G>::vertex_descriptor u, v;
    typename boost::graph_traits<G>::edge_descriptor e;
    G g;
  };

