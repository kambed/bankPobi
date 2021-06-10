//
// Created by student on 10.06.2021.
//

#ifndef BANK_TEMPLATES_H
#define BANK_TEMPLATES_H

/// \tparam T
/// \tparam T2
/// \param repository
/// \return std::vector<T>
template <class T,class T2>
std::vector<T> findAllTemplate(T2 repository)
{
    auto function = [&](const T &ptr)->bool{return(true);};
    return repository->findBy(function);
}

/// \tparam T
/// \tparam T2
/// \param predicate
/// \param objects
/// \return std::vector<T>
template <class T,class T2>
std::vector<T> findByTemplate(T2 predicate,std::vector<T> objects)
{
    std::vector<T> found;
    for (int i = 0; i < objects.size(); i++) {
        T object = objects[i];
        if (object != nullptr && predicate(object)) {
            found.push_back(object);
        }
    }
    return found;
}

#endif //BANK_TEMPLATES_H
