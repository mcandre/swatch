task :editorconfig=> [] do
  sh 'flcl . | xargs -n 100 editorconfig-cli check'
end

task :astyle_apply => [] do
  begin
    sh 'find . -type d -name android -prune -o -type f -name "*.java" -o -name "*.cpp" -o -name "*.[ch]" -exec astyle {} \\; | grep -v Unchanged'
  rescue
  end
end

task :astyle => [] do
  begin
    sh 'find . -type d -name android -prune -o -type f -name "*.java" -o -name "*.cpp" -o -name "*.[ch]" -exec astyle --dry-run {} \\; | grep -v Unchanged'
  rescue
  end
end

task :clean_astyle => [] do
  sh 'find . -type f -name "*.orig" -exec rm {} \\;'
end

task :pep8 => [] do
  sh 'find . -name node_modules -prune -o -name bower_components -prune -o -name "*.py" -exec pep8 {} \\;'
end

task :funk => [] do
  sh 'funk .'
end

task :lint => [
  :editorconfig,
  :astyle,
  :pep8,
  :funk
] do
end

task :clean => [
  :clean_astyle
] do
end
