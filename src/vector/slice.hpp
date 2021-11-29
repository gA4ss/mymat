template <class T>
Vector<T> slice(const Vector<T>& vec, size_t i, size_t ic=0) {
  i = __fix_index(i);
  if (ic == 0) ic = vec.size() - i;
  vector_size_is_out_of_range_exception(vec, i+ic-1);

  std::vector<T> _vec;
  std::vector<T> ivec = vec.value();
  // _vec.resize(ic);
  _vec.insert(_vec.begin(), ivec.begin()+i, ivec.begin()+i+ic);
  return Vector<T>(_vec);
}