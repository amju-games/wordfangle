// -----------------------------------------------------------------------------
// glboiler - Jason Colman 2016-2017 - OpenGL experiments
// -----------------------------------------------------------------------------

#pragma once

#include <string>

class gl_shader 
{
public:
  ~gl_shader();

  bool load(const std::string& vert_filename, const std::string& frag_filename);

  virtual void upload_on_gl_thread();
  virtual void use_on_gl_thread();
  virtual void destroy_on_gl_thread();

  void set_float_on_gl_thread(const std::string& name, float f);
  void set_int_on_gl_thread(const std::string& name, int i);

private:
  unsigned int m_program_id = 0;
  std::string m_vert_shader_filename;
  std::string m_frag_shader_filename;
  std::string m_vert_shader_source;
  std::string m_frag_shader_source;
  bool m_compiled_ok = false;
  bool m_destroy_called = false;
};

