#ifndef CARRENTAL_REPOSITORY_H
#define CARRENTAL_REPOSITORY_H

#include <vector>
#include <memory>
#include <functional>

template<class T> class Repository
{
protected:
    std::vector<std::shared_ptr<T>> objects;
public:
    std::shared_ptr<T> get(int index) const {
        if(objects.size()>index)
            return std::shared_ptr<T>();
        else
            return nullptr;
    }

    void add(std::shared_ptr<T> object) {
        if(object != nullptr)
            objects.push_back(object);
    }

    void remove(std::shared_ptr<T> object) {
        if(object != nullptr)
            objects.erase(std::remove(objects.begin(), objects.end(), object));
    }

    int getSize() const {
        return objects.size();
    }

    const std::string report() const {
        std::string rentlist=" ";
        for(int i=0;i<getSize();i++)
            rentlist=rentlist + "\n" + objects[i]->getInfo();
        return rentlist;
    }

    std::vector<std::shared_ptr<T>> findBy(std::function<bool(std::shared_ptr<T>)> predicate) const {
        std::vector<std::shared_ptr<T>> found;
        for (unsigned int i = 0; i < objects.size(); i++) {
            std::shared_ptr<T> rent = objects[i];
            if (rent != nullptr && predicate(rent))
                found.push_back(rent);
        }
        return found;
    }

    std::vector<std::shared_ptr<T>> findAll() {
        return findBy(true);
    }
};

#endif //CARRENTAL_REPOSITORY_H
